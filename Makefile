TASMOTA_VERSION=v5.13.0

default: build_sonoff build_sonoff-minimal

chown:
	chown -R $(UID) build

ci: full-clean default

build_%: download update_user-config_$* venv
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

update_user-config_%: venv
	./venv/bin/python update.py config_$*.yml
	cd tasmota && git --no-pager diff -w sonoff/user_config.h

venv:
	virtualenv -p python2 venv
	./venv/bin/pip install -r requirements.txt

.PHONY: venv
