## ClapPluginCppTemplate

A basic template with as few lines of code as possible for someone starting out building a clap plugin in c++. To get the infamous gain plugin ready to be used in a host:
```
git clone https://github.com/witte/ClapPluginCppTemplate.git
cd ClapPluginCppTemplate
cmake -S . -B build
cmake --build build     # plugin will be at './build/ClapPluginCppTemplate.clap'
```
<br>

- if the [clap SDK](https://github.com/free-audio/clap) and the [clap c++ helpers](https://github.com/free-audio/clap-helpers) are available through cmake's `find_package` anywhere in your machine they will be used, otherwise they will be downloaded and setup automatically.
- macOS only for now
- contributions are welcome!

## License
MIT