#include "../tomoko.hpp"
Presentation* presentation = nullptr;

Presentation::Presentation() {
  presentation = this;

  libraryMenu.setText("Library");
  for(auto& emulator : program->emulators) {
    for(auto& media : emulator->media) {
      if(!media.bootable) continue;
      auto item = new MenuItem{&libraryMenu};
      item->setText({media.name, " ..."}).onActivate([=] {
        directory::create({settings["Library/Location"].text(), media.name});
        auto location = BrowserDialog()
        .setTitle({"Load ", media.name})
        .setPath({settings["Library/Location"].text(), media.name})
        .setFilters(string{media.name, "|*.", media.type})
        .openFolder();
        if(directory::exists(location)) {
          program->loadMedia(location);
        }
      });
      loadBootableMedia.append(item);
    }
  }

  systemMenu.setText("System").setVisible(false);
  powerSystem.setText("Power").onActivate([&] { program->powerCycle(); });
  resetSystem.setText("Reset").onActivate([&] { program->softReset(); });
  unloadSystem.setText("Unload").onActivate([&] { program->unloadMedia(); drawSplashScreen(); });

  settingsMenu.setText("Settings");
  videoScaleMenu.setText("Video Scale");
  if(settings["Video/Scale"].text() == "Small") videoScaleSmall.setChecked();
  if(settings["Video/Scale"].text() == "Medium") videoScaleMedium.setChecked();
  if(settings["Video/Scale"].text() == "Large") videoScaleLarge.setChecked();
  videoScaleSmall.setText("Small").onActivate([&] {
    settings["Video/Scale"].setValue("Small");
    resizeViewport();
  });
  videoScaleMedium.setText("Medium").onActivate([&] {
    settings["Video/Scale"].setValue("Medium");
    resizeViewport();
  });
  videoScaleLarge.setText("Large").onActivate([&] {
    settings["Video/Scale"].setValue("Large");
    resizeViewport();
  });
  aspectCorrection.setText("Aspect Correction").setChecked(settings["Video/AspectCorrection"].boolean()).onToggle([&] {
    settings["Video/AspectCorrection"].setValue(aspectCorrection.checked());
    resizeViewport();
  });
  videoFilterMenu.setText("Video Filter");
  if(settings["Video/Filter"].text() == "None") videoFilterNone.setChecked();
  if(settings["Video/Filter"].text() == "Blur") videoFilterBlur.setChecked();
  videoFilterNone.setText("None").onActivate([&] {
    settings["Video/Filter"].setValue("None");
    program->updateVideoFilter();
  });
  videoFilterBlur.setText("Blur").onActivate([&] {
    settings["Video/Filter"].setValue("Blur");
    program->updateVideoFilter();
  });
  colorEmulation.setText("Color Emulation").setChecked(settings["Video/ColorEmulation"].boolean()).onToggle([&] {
    settings["Video/ColorEmulation"].setValue(colorEmulation.checked());
    program->updateVideoPalette();
  });
  maskOverscan.setText("Mask Overscan").setChecked(settings["Video/Overscan/Mask"].boolean()).onToggle([&] {
    settings["Video/Overscan/Mask"].setValue(maskOverscan.checked());
  });
  loadShaders();
  synchronizeVideo.setText("Synchronize Video").setChecked(settings["Video/Synchronize"].boolean()).onToggle([&] {
    settings["Video/Synchronize"].setValue(synchronizeVideo.checked());
    video->set(Video::Synchronize, synchronizeVideo.checked());
  });
  synchronizeAudio.setText("Synchronize Audio").setChecked(settings["Audio/Synchronize"].boolean()).onToggle([&] {
    settings["Audio/Synchronize"].setValue(synchronizeAudio.checked());
    audio->set(Audio::Synchronize, synchronizeAudio.checked());
  });
  muteAudio.setText("Mute Audio").setChecked(settings["Audio/Mute"].boolean()).onToggle([&] {
    settings["Audio/Mute"].setValue(muteAudio.checked());
    program->updateAudioVolume();
  });
  showStatusBar.setText("Show Status Bar").setChecked(settings["UserInterface/ShowStatusBar"].boolean()).onToggle([&] {
    settings["UserInterface/ShowStatusBar"].setValue(showStatusBar.checked());
    statusBar.setVisible(showStatusBar.checked());
    if(visible()) resizeViewport();
  });
  showConfiguration.setText("Configuration ...").onActivate([&] { settingsManager->show(2); });

  toolsMenu.setText("Tools").setVisible(false);
  saveStateMenu.setText("Save State");
  saveSlot1.setText("Slot 1").onActivate([&] { program->saveState(1); });
  saveSlot2.setText("Slot 2").onActivate([&] { program->saveState(2); });
  saveSlot3.setText("Slot 3").onActivate([&] { program->saveState(3); });
  saveSlot4.setText("Slot 4").onActivate([&] { program->saveState(4); });
  saveSlot5.setText("Slot 5").onActivate([&] { program->saveState(5); });
  loadStateMenu.setText("Load State");
  loadSlot1.setText("Slot 1").onActivate([&] { program->loadState(1); });
  loadSlot2.setText("Slot 2").onActivate([&] { program->loadState(2); });
  loadSlot3.setText("Slot 3").onActivate([&] { program->loadState(3); });
  loadSlot4.setText("Slot 4").onActivate([&] { program->loadState(4); });
  loadSlot5.setText("Slot 5").onActivate([&] { program->loadState(5); });
  cheatEditor.setText("Cheat Editor").onActivate([&] { toolsManager->show(0); });
  stateManager.setText("State Manager").onActivate([&] { toolsManager->show(1); });

  statusBar.setFont(Font().setBold());
  statusBar.setVisible(settings["UserInterface/ShowStatusBar"].boolean());

  onClose([&] { program->quit(); });

  setTitle({"higan v", Emulator::Version});
  setResizable(false);
  setBackgroundColor({0, 0, 0});
  resizeViewport();
  setCentered();
}

auto Presentation::updateEmulator() -> void {
  if(!emulator) return;
  resetSystem.setVisible(emulator->information.resettable);
  inputPort1.setVisible(false).reset();
  inputPort2.setVisible(false).reset();
  inputPort3.setVisible(false).reset();

  for(auto n : range(emulator->port)) {
    if(n >= 3) break;
    auto& port = emulator->port[n];
    auto& menu = (n == 0 ? inputPort1 : n == 1 ? inputPort2 : inputPort3);
    menu.setText(port.name);

    Group devices;
    for(auto& device : port.device) {
      MenuRadioItem item{&menu};
      item.setText(device.name).onActivate([=] {
        auto path = string{emulator->information.name, "/", port.name}.replace(" ", "");
        settings[path].setValue(device.name);
        emulator->connect(port.id, device.id);
      });
      devices.append(item);
    }
    if(devices.objectCount() > 1) {
      auto path = string{emulator->information.name, "/", port.name}.replace(" ", "");
      auto device = settings(path).text();
      for(auto object : devices.objects()) {
        if(auto item = object.cast<MenuRadioItem>()) {
          if(item.text() == device) item.setChecked().doActivate();
        }
      }
      menu.setVisible();
    }
  }

  systemMenuSeparatorPorts.setVisible(inputPort1.visible() || inputPort2.visible() || inputPort3.visible());
}

auto Presentation::resizeViewport() -> void {
  signed width   = emulator ? emulator->information.width  : 256;
  signed height  = emulator ? emulator->information.height : 240;
  double stretch = emulator ? emulator->information.aspectRatio : 1.0;
  if(stretch != 1.0) {
    //aspect correction is always enabled in fullscreen mode
    if(!fullScreen() && !settings["Video/AspectCorrection"].boolean()) stretch = 1.0;
  }

  signed scale = 2;
  if(settings["Video/Scale"].text() == "Small" ) scale = 2;
  if(settings["Video/Scale"].text() == "Medium") scale = 3;
  if(settings["Video/Scale"].text() == "Large" ) scale = 4;

  signed windowWidth = 0, windowHeight = 0;
  if(!fullScreen()) {
    windowWidth  = 256 * scale * (settings["Video/AspectCorrection"].boolean() ? 8.0 / 7.0 : 1.0);
    windowHeight = 240 * scale;
  } else {
    windowWidth  = geometry().width();
    windowHeight = geometry().height();
  }

  signed multiplier = min(windowWidth / (signed)(width * stretch), windowHeight / height);
  width = width * multiplier * stretch;
  height = height * multiplier;

  if(!fullScreen()) setSize({windowWidth, windowHeight});
  viewport.setGeometry({(windowWidth - width) / 2, (windowHeight - height) / 2, width, height});

  if(!emulator) drawSplashScreen();
}

auto Presentation::toggleFullScreen() -> void {
  if(fullScreen() == false) {
    menuBar.setVisible(false);
    statusBar.setVisible(false);
    setResizable(true);
    setFullScreen(true);
    if(!input->acquired()) input->acquire();
  } else {
    if(input->acquired()) input->release();
    setFullScreen(false);
    setResizable(false);
    menuBar.setVisible(true);
    statusBar.setVisible(settings["UserInterface/ShowStatusBar"].boolean());
  }

  Application::processEvents();
  resizeViewport();
}

auto Presentation::drawSplashScreen() -> void {
  if(!video) return;
  uint32* output;
  unsigned length;
  if(video->lock(output, length, 256, 240)) {
    for(auto y : range(240)) {
      uint32* dp = output + y * (length >> 2);
      for(auto x : range(256)) *dp++ = 0xff000000;
    }
    video->unlock();
    video->refresh();
  }
}

auto Presentation::loadShaders() -> void {
  if(settings["Video/Driver"].text() != "OpenGL") {
    videoShaderMenu.setVisible(false);
    return;
  }

  auto pathname = locate({localpath(), "tomoko/"}, "Video Shaders/");
  for(auto shader : directory::folders(pathname, "*.shader")) {
    MenuRadioItem item{&videoShaderMenu};
    item.setText(string{shader}.rtrim(".shader/", 1L)).onActivate([=] {
      settings["Video/Shader"].setValue({pathname, shader});
      program->updateVideoFilter();
    });
    videoShaders.append(item);
  }

  videoShaderMenu.setText("Video Shaders");
  videoShaderNone.setChecked().setText("None").onActivate([=] {
    settings["Video/Shader"].setValue("None");
    program->updateVideoFilter();
  });

  for(auto object : videoShaders.objects()) {
    if(auto radioItem = dynamic_cast<mMenuRadioItem*>(object.data())) {
      if(settings["Video/Shader"].text() == string{pathname, radioItem->text(), ".shader/"}) {
        radioItem->setChecked();
      }
    }
  }
}