TASMOTA_VERSION=v6.2.1

default: build_sonoff build_sonoff-minimal

chown:
	chown -R $(UID) build

ci: full-clean default

build_%: download
	$(MAKE) update_user-config_$*
	cd tasmota && ../venv/bin/platformio run -e $*
	mkdir -p build
	cp tasmota/.pioenvs/$*/firmware.bin build/$*.bin

clean:
	rm -rf tasmota venv

download:
	git clone https://github.com/arendst/Sonoff-Tasmota.git tasmota
	cd tasmota && git reset --hard $(TASMOTA_VERSION)

full-clean: clean
	rm -rf build
