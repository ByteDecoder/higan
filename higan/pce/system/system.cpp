#include <pce/pce.hpp>

namespace higan::PCEngine {

Scheduler scheduler;
System system;
#include "serialization.cpp"

auto System::run() -> void {
  if(scheduler.enter() == Event::Frame) vce.refresh();
}

auto System::runToSave() -> void {
  scheduler.enter(Scheduler::Mode::Serialize);
}

auto System::load(Node::Object from) -> void {
  if(node) unload();

  information = {};
  if(interface->name() == "PC Engine" ) information.model = Model::PCEngine;
  if(interface->name() == "SuperGrafx") information.model = Model::SuperGrafx;

  higan::audio.reset(interface);

  node = Node::append<Node::System>(nullptr, from, interface->name());

  scheduler.reset();
  cpu.load(node, from);
  vce.load(node, from);
  psg.load(node, from);
  cartridge.load(node, from);
  controllerPort.load(node, from);
}

auto System::save() -> void {
  if(!node) return;
  cartridge.save();
}

auto System::unload() -> void {
  if(!node) return;
  save();
  cartridge.port = {};
  controllerPort.port = {};
  cpu.unload();
  vce.unload();
  psg.unload();
  node = {};

  higan::audio.reset();
}

auto System::power() -> void {
  for(auto& setting : node->find<Node::Setting>()) setting->setLatch();

  cartridge.power();
  cpu.power();
  vce.power();
  vpc.power();
  vdc0.power();
  vdc1.power();
  psg.power();
  scheduler.power(cpu);

  serializeInit();
}

}
