# Keymap for the Keychron K3 Pro keyboard

Get QMK
```
cd ~
mkdir qmk && cd qmk
python3 -m venv qmk-venv
. qmk-venv/bin/activate
python3 -m pip install qmk

qmk setup -H $HOME/qmk/wireless_playground -b wireless_playground Keychron/qmk_firmware
* agree to set QMK home folder
```

Get keymap
```
git clone https://github.com/opestov/qmk-keymap.git
ln -s ~/qmk/qmk-keymap/ ~/qmk/wireless_playground/keyboards/keychron/k3_pro/ansi/rgb/keymaps/1
```

Compile/Flash
```
. ~/qmk/qmk-venv/bin/activate && cd ~/qmk/wireless_playground
qmk clean
qmk flash -kb keychron/k3_pro/ansi/rgb -km 1
```


