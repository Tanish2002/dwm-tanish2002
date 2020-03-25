# Changes

+ **added ewmh tags patch** to make polybar work 
+ **added Restartsig patch** to restart without killing the session
+ **added focusonclick** to switch focus only by mouse click
+ **changed almost all the keybindings** to make it comfortable for me


## Installation 

```
git clone https://gitlab.com/Tanish2002/dwm-tanish2002.git
cd st
sudo make install
```


## More Info

+ **Check out [Mitchweaver's Repo](https://github.com/mitchweaver/suckless/tree/master/dwm)** (my fork is based on his).

+ **All the patches are preapplied, if want to remove a patch they are loacated in the [`patches` Folder](patches)**

+ **Focusonclick is not patch** you can disable it by un-commenting `[EnterNotify] = enternotify,` in `dwm.c`

Enjoy!


