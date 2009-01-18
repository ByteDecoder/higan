class Cheat {
public:
  enum type_t {
    ProActionReplay,
    GameGenie,
  };

  struct cheat_t {
    bool enabled;
    string code;
    string desc;

    unsigned count;
    array<unsigned> addr;
    array<uint8_t> data;

    cheat_t& operator=(const cheat_t&);
    bool operator<(const cheat_t&);
  };

  bool decode(const char *s, cheat_t &item) const;
  bool read(unsigned addr, uint8_t &data) const;

  inline bool enabled() const { return cheat_system_enabled; }
  inline unsigned count() const { return code.size(); }
  inline bool exists(unsigned addr) const { return mask[addr >> 3] & 1 << (addr & 7); }

  bool add(bool enable, const char *code, const char *desc);
  bool edit(unsigned i, bool enable, const char *code, const char *desc);
  bool remove(unsigned i);
  bool get(unsigned i, cheat_t &item) const;

  bool enabled(unsigned i) const;
  void enable(unsigned i);
  void disable(unsigned i);

  bool load(const char *fn);
  bool save(const char *fn) const;

  void sort();
  void clear();

  Cheat();

private:
  bool cheat_system_enabled;
  uint8_t mask[0x200000];
  vector<cheat_t> code;

  bool decode(const char *str, unsigned &addr, uint8_t &data, type_t &type) const;
  bool encode(string &str, unsigned addr, uint8_t data, type_t type) const;

  void update_cheat_status();
  unsigned mirror_address(unsigned addr) const;

  void update(const cheat_t& item);
  void set(unsigned addr);
  void clear(unsigned addr);

  string& encode_description(string &desc) const;
  string& decode_description(string &desc) const;
};

extern Cheat cheat;
