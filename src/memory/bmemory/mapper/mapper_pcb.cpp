//SHVC-1A3B-01
//SHVC-1A3B-11
//SHVC-1A3B-12
//SHVC-1A3B-13
mapper(shvc_1a3b_13) {
  map(LINEAR, 0x00, 0x1f, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0x70, 0x7f, 0x0000, 0xffff, MAP_RAM);
  map(LINEAR, 0x80, 0x9f, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0xf0, 0xff, 0x0000, 0xffff, MAP_RAM);
}

//SHVC-1A3B-20
mapper(shvc_1a3b_20) {
  map(LINEAR, 0x00, 0x7f, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0x70, 0x7f, 0x0000, 0x7fff, MAP_RAM);
  map(LINEAR, 0x80, 0xff, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0xf0, 0xff, 0x0000, 0x7fff, MAP_RAM);
}

//SHVC-1A3M-10
//SHVC-1A3M-20
//SHVC-1A3M-21
//SHVC-1A3M-30
mapper(shvc_1a3m_30) {
  map(LINEAR, 0x00, 0x7f, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0x70, 0x7f, 0x0000, 0x7fff, MAP_RAM);
  map(LINEAR, 0x80, 0xff, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0xf0, 0xff, 0x0000, 0x7fff, MAP_RAM);
}

//SHVC-1J3M-01
//SHVC-1J3M-10
//SHVC-1J3M-11
//SHVC-1J3M-20
mapper(shvc_1j3m_20) {
  map(SHADOW, 0x00, 0x3f, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0x20, 0x3f, 0x6000, 0x7fff, MAP_RAM);
  map(LINEAR, 0x40, 0x7f, 0x0000, 0xffff, MAP_ROM);
  map(SHADOW, 0x80, 0xbf, 0x8000, 0xffff, MAP_ROM);
  map(LINEAR, 0xa0, 0xbf, 0x6000, 0x7fff, MAP_RAM);
  map(LINEAR, 0xc0, 0xff, 0x0000, 0xffff, MAP_ROM);
}

//BSC-1A5M-01
//
//$[c0-ef]:[0000-ffff] BSX
mapper(bsc_1a5m_01) {
  map(LINEAR, 0x00, 0x1f, 0x8000, 0xffff, MAP_ROM, 0x000000);
  map(LINEAR, 0x20, 0x3f, 0x8000, 0xffff, MAP_ROM, 0x100000);
  map(LINEAR, 0x70, 0x7f, 0x0000, 0x7fff, MAP_RAM);
  map(LINEAR, 0x80, 0x9f, 0x8000, 0xffff, MAP_ROM, 0x200000);
  map(LINEAR, 0xa0, 0xbf, 0x8000, 0xffff, MAP_ROM, 0x100000);
  map(LINEAR, 0xf0, 0xff, 0x0000, 0x7fff, MAP_RAM);
}

//BSC-1A7M-01
//
//$[c0-ef]:[0000-ffff] BSX
mapper(bsc_1a7m_01) {
  map(LINEAR, 0x00, 0x1f, 0x8000, 0xffff, MAP_ROM, 0x000000);
  map(LINEAR, 0x20, 0x3f, 0x8000, 0xffff, MAP_ROM, 0x100000);
  map(LINEAR, 0x70, 0x7f, 0x0000, 0x7fff, MAP_RAM);
  map(LINEAR, 0x80, 0x9f, 0x8000, 0xffff, MAP_ROM, 0x000000);
  map(LINEAR, 0xa0, 0xbf, 0x8000, 0xffff, MAP_ROM, 0x100000);
  map(LINEAR, 0xf0, 0xff, 0x0000, 0x7fff, MAP_RAM);
}

//BSC-1A7M-10
//
//$[c0-ef]:[0000-ffff] BSX
mapper(bsc_1a7m_10) {
  map(LINEAR, 0x00, 0x1f, 0x8000, 0xffff, MAP_ROM, 0x000000);
  map(LINEAR, 0x20, 0x3f, 0x8000, 0xffff, MAP_ROM, 0x100000);
  map(LINEAR, 0x70, 0x7f, 0x0000, 0x7fff, MAP_RAM);
  map(LINEAR, 0x80, 0x9f, 0x8000, 0xffff, MAP_ROM, 0x200000);
  map(LINEAR, 0xa0, 0xbf, 0x8000, 0xffff, MAP_ROM, 0x100000);
  map(LINEAR, 0xf0, 0xff, 0x0000, 0x7fff, MAP_RAM);
}
