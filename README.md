# Keymap for the Keychron K3 Pro keyboard

Get QMK
```
cd ~
mkdir qmk && cd qmk
python3 -m venv qmk-venv
. qmk-venv/bin/activate

python3 -m pip install qmk
qmk config user.qmk_home=$HOME/qmk/firmware

qmk setup Keychron/qmk_firmware

cd firmware && git checkout wireless_playground
make git-submodule

# test by building the default firmware
qmk compile -kb keychron/k3_pro/ansi/rgb -km default
```

Get keymap
```
git clone https://github.com/opestov/qmk-keymap.git
ln -s ~/qmk/qmk-keymap/ ~/qmk/firmware/keyboards/keychron/k3_pro/ansi/rgb/keymaps/1
```

Compile/Flash
```
. ~/qmk/qmk-venv/bin/activate && cd ~/qmk/firmware
qmk clean
qmk flash -kb keychron/k3_pro/ansi/rgb -km 1
```

Host OS

* Windows: install ru+.
* Linux: change `/usr/share/X11/xkb/symbols/custom` to `custom`. Make sure that level3 switcher is set to Right Alt.
```
$ gsettings get org.gnome.desktop.input-sources xkb-options
['lv3:menu_switch']
$ gsettings set org.gnome.desktop.input-sources xkb-options "['lv3:ralt_switch']"
$ gsettings get org.gnome.desktop.input-sources xkb-options
['lv3:ralt_switch']
```
