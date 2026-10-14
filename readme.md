How to use (Windows 11):

1) git clone --branch ctrl-v1-reactive --recurse-submodules https://github.com/Kaminate/qmk_firmware_massdrop_ctrl_v1.git
2) install QMK MSYS from https://msys.qmk.fm/
3) from the QMK MSYS app, cd to wherever you cloned qmk_firmware_massdrop_ctrl_v1 to
4) qmk compile -kb massdrop/ctrl -km reactive
5) install the Drop Keyboard Configurator from... the internet idk
6) flash the keyboard from the Drop Keyboard Configurator by going to Flash Firmware --> DROP CTRL V1 --> CHOOSE A FILE... --> qmk_firmware_massdrop_ctrl_v1/massdrop_ctrl_reactive.bin

note:
- the code for the keyboard is in keyboards\massdrop\ctrl\keymaps\reactive\keymap.c
- specifically in keyboard_post_init_user()
- so if you change the code, repeat steps 4-6

