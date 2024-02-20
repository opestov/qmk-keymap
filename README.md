# Keymap for the Keychron K3 Pro keyboard

[Setup](https://opestov.github.io/k3/index.html)  QMK environment, then

```
cd ~
git clone https://github.com/opestov/qmk-keymap.git
ln -s /home/ubuntu/qmk-keymap/ /home/ubuntu/qmk_firmware/keyboards/keychron/k3_pro/ansi/rgb/keymaps/1
cd qmk_firmware
qmk clean
qmk compile -kb keychron/k3_pro/ansi/rgb -km 1
```
