/*
  libconfig : version 0.10 ~byuu (10/10/06)
*/

#ifndef __LIBCONFIG
#define __LIBCONFIG

#include "libarray.h"
#include "libstring.h"

class Config;

class Setting {
  friend class Config;

protected:
uint data, type, def;

public:
enum {
  BOOL             =  0,
  BOOLEAN          =  0,
  TRUE_FALSE       =  0,
  ENABLED_DISABLED =  1,
  ON_OFF           =  2,
  YES_NO           =  3,
  DEC              =  4,
  HEX              =  5,
  HEX8             =  6,
  HEX16            =  7,
  HEX24            =  8,
  HEX32            =  9,
  STR              = 10,
};
char *name, *desc;
string char_data, char_def;
  virtual void  toggle();
  virtual uint  get();
  virtual void  set(uint _data);

  virtual char *sget();
  virtual void  sset(const char *_data);

  Setting(Config *_parent, char *_name, char *_desc, uint  _data, uint _type);
  Setting(Config *_parent, char *_name, char *_desc, char *_data);

  template<typename T> inline operator T() { return (T)get(); }
  template<typename T> inline Setting &operator=(const T &x) { set(x); return *this; }
  template<typename T> inline bool operator==(const T &x) { return (T)get() == x; }
  template<typename T> inline bool operator!=(const T &x) { return (T)get() != x; }
  template<typename T> inline bool operator>=(const T &x) { return (T)get() >= x; }
  template<typename T> inline bool operator> (const T &x) { return (T)get() >  x; }
  template<typename T> inline bool operator<=(const T &x) { return (T)get() <= x; }
  template<typename T> inline bool operator< (const T &x) { return (T)get() <  x; }
};

class Config {
protected:
array<Setting*> list;
uint list_count;

string data;
stringarray line, part, subpart;

uint  string_to_uint(uint type, char *input);
char *uint_to_string(uint type, uint  input);

public:
  void add(Setting *setting);
  bool load(char *fn);
  bool load(string &fn);
  bool save(char *fn);
  bool save(string &fn);
  Config();
};

#endif
