TASMOTA_VERSION=v8.3.1
export PLATFORMIO_BUILD_FLAGS=-DUSE_CONFIG_OVERRIDE

default: build_tasmota build_tasmota-minimal

chown:
	chown -R $(UID) build

ci: full-clean default

build_%: download korvike venv
	./korvike -i user_config_override.h -o tasmota/tasmota/user_config_override.h
	cd tasmota && ../venv/bin/platformio run -e $*
	mkdir -p build
	cp tasmota/.pioenvs/$*/firmware.bin build/$*.bin

clean final:
	rm -rf korvike tasmota venv

download:
	git clone https://github.com/arendst/Sonoff-Tasmota.git tasmota
	cd tasmota && git reset --hard $(TASMOTA_VERSION)

full-clean: clean
	rm -rf build

korvike:
	curl -sSfL https://github.com/Luzifer/korvike/releases/download/v0.5.0/korvike_linux_amd64.tar.gz | tar -xz
	mv korvike_linux_amd64 korvike

venv:
	virtualenv venv
	./venv/bin/pip install -r requirements.txt

.PHONY: venv

manual:
	vault2env --key=secret/jenkins/build-tasmota -- bash -eux -o pipefail -c 'env | grep -v PATH > ./env && docker run --rm -i --env-file=env -e UID=$(shell id -u) -v "$(CURDIR):/src" -w /src python make ci chown final'
