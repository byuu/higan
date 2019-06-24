struct MasterSystem : Cartridge {
  auto name() -> string override { return "Master System"; }
  auto export(string location) -> vector<uint8_t> override;
  auto heuristics(vector<uint8_t>& data, string location) -> string override;
};

auto MasterSystem::export(string location) -> vector<uint8_t> {
  vector<uint8_t> data;
  append(data, {location, "program.rom"});
  return data;
}

auto MasterSystem::heuristics(vector<uint8_t>& data, string location) -> string {
  string s;
  s += "game\n";
  s +={"  name:  ", Location::prefix(location), "\n"};
  s +={"  label: ", Location::prefix(location), "\n"};
  s += "  board\n";
  s += "    memory\n";
  s += "      type: ROM\n";
  s +={"      size: 0x", hex(data.size()), "\n"};
  s += "      content: Program\n";
  s += "    memory\n";
  s += "      type: ROM\n";
  s += "      size: 0x8000\n";
  s += "      content: Save\n";
  return s;
}
