
-----
- Note Taking
  - IPFS note taking web
    - Markdown web
    - Table of content Tree
  - UML umletino online ipfs
- plan naming convention
  - server
    - vm
    - docker
    - kubernetes
  - user, group
  - access, ssh, vpn
  - components
    - db
    - fs
    - app
- hardware
  - personal laptop
  - homelab computer
    - https://github.com/lisenet/kubernetes-homelab
   
    - minipc 16gb ram
  
minipc - keyboard - mouse - video adapter - cable hdmi

minipc - home modem/router - network cable
minipc - usb boot operating system

‌

debian - pendrive
root
dev01

debian - network - cable ethernet


https://wiki.debian.org/SourcesList

apt -y update && apt -y upgrade && apt -y autoremove
apt -y full-upgrade

ssh dev01@192.168.1.100

  dev01 -
  arc‌a - 
  192.168.1.100

```

root@arca:~# apt install tightvncserver

dev01@arca:~$ vncserver :1

You will require a password to access your desktops.

Password: 
Verify:   
Would you like to enter a view-only password (y/n)? n
xauth:  file /home/dev01/.Xauthority does not exist

New 'X' desktop is arca:1

Creating default startup script /home/dev01/.vnc/xstartup
Starting applications specified in /home/dev01/.vnc/xstartup
Log file is /home/dev01/.vnc/arca:1.log


dev01@arca:~$ vncserver -kill :1
Killing Xtightvnc process ID 1942



dev01@arca:~$ vi ~/.vnc/xstartup

#!/bin/sh

xrdb "$HOME/.Xresources"
xsetroot -solid grey
#x-terminal-emulator -geometry 80x24+10+10 -ls -title "$VNCDESKTOP Desktop" &
#x-window-manager &
# Fix to make GNOME work
export XKL_XMODMAP_DISABLE=1
/etc/X11/Xsession
lxterminal & /usr/bin/lxsessoin -s LXDE &



dev01@arca:~$ tightvncserver :1

New 'X' desktop is arca:1

Starting applications specified in /home/dev01/.vnc/xstartup
Log file is /home/dev01/.vnc/arca:1.log




- Connecto VNC laptop client Remmina 
- 192.168.1.100:5901

- Running OK!


- Run VNCServer at startup


dev01@arca:~$ vi /etc/init.d/tightvncserver


---

root@arca:~# vi /etc/init.d/tightvncserver
root@arca:~# cat /etc/init.d/tightvncserver 
#!/bin/sh
### BEGIN INIT INFO
# Provides: tightvncserver
# Required-Start: $local_fs
# Required-Stop: $local_fs
# Default-Start: 2 3 4 5
# Default-Stop: 0 1 6
# Short-Description: Start/stop tightvncserver
### END INIT INFO

# More details see:
# http://www.penguintutor.com/linux/tightvnc

### Customize this entry
# Set the USER variable to the name of the user to start tightvncserver under
export USER=dev01
### End customization required

eval cd ~/$USER

case "$1" in
 start)
 su $USER -c '/usr/bin/tightvncserver :1'
 echo "Starting TightVNC server for $USER "
 ;;
 stop)
 pkill Xtightvnc
 echo "Tightvncserver stopped"
 ;;
 *)
 echo "Usage: /etc/init.d/tightvncserver {start|stop}"
 exit 1
 ;;
restart)
$0 stop
$0 start
;;
esac
exit 0

---
root@arca:~# chmod 775 /etc/init.d/tightvncserver 
root@arca:~# update-rc.d tightvncserver defaults
---
- reboot 
- check VNC connection 

dev01@arca:~$ cat .vnc/arca\:1.log 
14/05/23 16:14:03 Xvnc version TightVNC-1.3.10
14/05/23 16:14:03 Copyright (C) 2000-2009 TightVNC Group
14/05/23 16:14:03 Copyright (C) 1999 AT&T Laboratories Cambridge
14/05/23 16:14:03 All Rights Reserved.
14/05/23 16:14:03 See http://www.tightvnc.com/ for information on TightVNC
14/05/23 16:14:03 Desktop name 'X' (arca:1)
14/05/23 16:14:03 Protocol versions supported: 3.3, 3.7, 3.8, 3.7t, 3.8t
14/05/23 16:14:03 Listening for VNC connections on TCP port 5901
xrdb: No such file or directory
xrdb: can't open file '/home/dev01/.Xresources'


---
dev01@arca:~$ touch /home/dev01/.Xresources

dev01@arca:~$ chmod 775 /home/dev01/.Xresources

- journalctl - add dev01 to user group adm


dev01@arca:~$ systemctl status tightvncserver
● tightvncserver.service - LSB: Start/stop tightvncserver
     Loaded: loaded (/etc/init.d/tightvncserver; generated)
     Active: active (exited) since Sun 2023-05-14 16:49:46 CEST; 1min 30s ago
       Docs: man:systemd-sysv-generator(8)
    Process: 557 ExecStart=/etc/init.d/tightvncserver start (code=exited, status=0/SUCCESS)
        CPU: 2ms

May 14 16:49:46 arca systemd[1]: Starting tightvncserver.service - LSB: Start/stop tightvncserver...
May 14 16:49:46 arca tightvncserver[557]: /etc/init.d/tightvncserver: 1: cd: can't cd to /home/’dev01‘
May 14 16:49:46 arca tightvncserver[559]: su: user ’dev01‘ does not exist or the user entry does not contain all the re>
May 14 16:49:46 arca tightvncserver[557]: Starting TightVNC server for ’dev01‘
May 14 16:49:46 arca systemd[1]: Started tightvncserver.service - LSB: Start/stop tightvncserver.



dev01@arca:~$ systemctl status tightvncserver
● tightvncserver.service - LSB: Start/stop tightvncserver
     Loaded: loaded (/etc/init.d/tightvncserver; generated)
     Active: active (exited) since Sun 2023-05-14 16:52:50 CEST; 25s ago
       Docs: man:systemd-sysv-generator(8)
    Process: 558 ExecStart=/etc/init.d/tightvncserver start (code=exited, status=0/SUCCESS)
        CPU: 6ms

May 14 16:52:48 arca systemd[1]: Starting tightvncserver.service - LSB: Start/stop tightvncserver...
May 14 16:52:48 arca su[560]: (to dev01) root on none
May 14 16:52:48 arca su[560]: pam_unix(su:session): session opened for user dev01(uid=1001) by (uid=0)
May 14 16:52:50 arca tightvncserver[558]: Starting TightVNC server for dev01
May 14 16:52:50 arca systemd[1]: Started tightvncserver.service - LSB: Start/stop tightvncserver.
---
OK - VNC Running on startup!
---

- VNC web


```

homlab - router
static ip

local network - LAN - static ip - mac address 192.168.1.100

---

VNC
Remmina
( client laptop: apt -y install remmina )

[https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-vnc-on-debian-11](https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-vnc-on-debian-11 "smartCard-inline")
   
https://timmystuts.wordpress.com/2018/08/27/installing-a-lightweight-lxdevnc-desktop-environment-on-your-debian-vps/

apt update 
apt upgrade
apt dist-upgrade
apt -y autoremove

apt install tightvncserver




  - web3
- Goals
  - Simplicity
  - Open Source
  - GitOps
  - Share
  - Learn
  - Note taking
  - Change Managment
  - Monitoring
  - Scalability

-----

