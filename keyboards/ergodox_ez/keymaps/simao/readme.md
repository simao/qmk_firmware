More information can be found in the QMK docs: <https://docs.qmk.fm>

This needs dependencies to compile on arch:

- sudo pacman -S avr-gcc avr-libc teensy-loader-cli
- to debug: `yay -S hid_listen`
- build make ergodox_ez:simao (in root)
- to flash: sudo teensy-loader-cli -mmcu=atmega32u4 -v -w ergodox_ez_simao.hex
