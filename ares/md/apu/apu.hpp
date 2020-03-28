//Zilog Z80

struct APU : Z80, Z80::Bus, Thread {
  Node::Component node;
  Node::Memory debugRAM;
  Node::Instruction debugInstruction;
  Node::Notification debugInterrupt;

  inline auto synchronizing() const -> bool override { return scheduler.synchronizing(); }

  //z80.cpp
  auto load(Node::Object, Node::Object) -> void;
  auto unload() -> void;

  auto main() -> void;
  auto step(uint clocks) -> void override;

  auto enable(bool) -> void;
  auto power(bool reset) -> void;
  auto reset() -> void;

  auto setNMI(bool value) -> void;
  auto setINT(bool value) -> void;

  //bus.cpp
  auto read(uint16 address) -> uint8 override;
  auto write(uint16 address, uint8 data) -> void override;

  auto in(uint16 address) -> uint8 override;
  auto out(uint16 address, uint8 data) -> void override;

  //serialization.cpp
  auto serialize(serializer&) -> void;

private:
  Memory::Writable<uint8> ram;

  struct IO {
    uint9 bank;
  } io;

  struct State {
    uint1 enabled;
    uint1 nmiLine;
    uint1 intLine;
  } state;
};

extern APU apu;
