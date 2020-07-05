# Luzifer / tasmota-build

Inside this repostitory there is a small build environment to automatically configure and build a [Sonoff-Tasmota](https://github.com/arendst/Sonoff-Tasmota) image.

## Usage

- Adjust `config.yml` to your needs
  - `!undef` ensures the parameter is not defined
  - `!def` ensures the parameter is defined
  - `${VAR}` reads the contents of the parameter from the environment
  - Any other string will be inserted into the config
- Define a `env` file for everything you are reading from the environment (Format: `VAR=VALUE`, one per line)
- Build the firmware
    ```bash
    # docker run --rm -ti --env-file=env -e UID=$(id -u) -v $(pwd):/src -w /src python make default clean chown
    ```

Pay attention: When defining strings you need to wrap them in double quotes for the compiler to understand them as strings: `PARAM: '"mystring"'`. If you are defining numbers you will define them like this: `PARAM: '1'`. Constants are used like this: `PARAM: CONSTANT`.
