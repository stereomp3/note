- [x] [WebDAV](https://github.com/stereomp3/note/blob/main/linux/111semester02/03.md#WebDAV)
- [ ] [Whisper](https://github.com/stereomp3/note/blob/main/linux/111semester02/04.md#自動產生字幕)
- [x] [DNS server](https://github.com/stereomp3/note/blob/main/linux/111semester02/05.md#DNS_server)
- [x] [ docker web load balancing](https://github.com/stereomp3/note/blob/main/linux/111semester02/07.md#docker)
- [x] [jumpServer setup](https://github.com/stereomp3/note/blob/main/linux/111semester02/08.md#jumpServer)
- [x] [set up email server](https://github.com/stereomp3/note/blob/main/linux/111semester02/10.md#架設伺服器端)
- [ ] [Zabbix server setup](https://github.com/stereomp3/note/blob/main/linux/111semester02/10.md#Zabbix)
- [ ] [Zabbix client setup](https://github.com/stereomp3/note/blob/main/linux/111semester02/10.md#架設客戶端)
- [ ] [Zabbix set notification with email](https://github.com/stereomp3/note/blob/main/linux/111semester02/11.md#zabbix)
- [ ] [Zabbix notify with line](https://github.com/stereomp3/note/blob/main/linux/111semester02/12.md#Zabbix)
- [ ] [custom zabbix parameter (httpd、connections)](https://github.com/stereomp3/note/blob/main/linux/111semester02/12.md#custom_parameter)
- [ ] [Ansible setup](https://github.com/stereomp3/note/blob/main/linux/111semester02/13.md#Ansible)
- [ ] [Asinble playbook](https://github.com/stereomp3/note/blob/main/linux/111semester02/15.md#Asinble_playbook)



# WebDav

```
$ httpd -M | grep dav
$ mkdir /var/www/html/webdav
$ chown -R apache:apache /var/www/html
$ chmod -R 755 /var/www/html
$ vim /etc/httpd/conf.d/webdav.conf
```



```
DavLockDB /var/www/html/DavLock  
<VirtualHost *:80>
    ServerAdmin webmaster@localhost
    DocumentRoot /var/www/html/webdav/
    ErrorLog /var/log/httpd/error.log
    CustomLog /var/log/httpd/access.log combined
    Alias /webdav /var/www/html/webdav
    <Directory /var/www/html/webdav>
        DAV On
        #AuthType Basic
        #AuthName "webdav"
        #AuthUserFile /etc/httpd/.htpasswd
        #Require valid-user
        </Directory>
</VirtualHost>
```



```
$ systemctl restart httpd
```

login with windows

`\\192.168.42.131\webdav`





# DNS server

```sh
systemctl start named
nslookup ftp.a.com 192.168.42.131  # nslookup [DNS name] [IP]


end
systemctl stop named
```





# docker web load balancing

```
$ systemctl start docker
$ netstat -tunlp | grep 8080
$ docker run -d -p 8080:80 centos:0.01 /usr/sbin/apachectl -D FOREGROUND 
$ docker run -d -p 8001:80 -v /home/user/class/webs/web1:/var/www/html --name web1 centos:0.01 /usr/sbin/apachectl -DFOREGROUND
$ docker run -d -p 8002:80 -v /home/user/class/webs/web2:/var/www/html --name web2 centos:0.01 /usr/sbin/apachectl -DFOREGROUND
$ docker run -d -p 8003:80 -v /home/user/class/webs/web3:/var/www/html --name web3 centos:0.01 /usr/sbin/apachectl -DFOREGROUND
$ docker run -d -p 8004:80 -v /home/user/class/webs/web4:/var/www/html --name web4 centos:0.01 /usr/sbin/apachectl -DFOREGROUND
$ docker run -d -p 8005:80 -v /home/user/class/webs/web5:/var/www/html --name web5 centos:0.01 /usr/sbin/apachectl -DFOREGROUND

end
$ docker rm -f `docker ps -a -q`
```





# jumpServer setup

```
netstat -tunlp | grep 80
systemctl stop httpd
cd Dockerfile
```



# Zabbix server setup

test

```
cat /dev/urandom | md5sum
```



test02

```
systemctl stop httpd
```





test03

```
ssh
```



# ansible

```
ansible-playbook hello.yml
```



```
--- 
- hosts: server1
  tasks:
  - name: show date
    command: date
    register: show_date
  - name: install httpd server
    service: name=httpd state=restarted
  - name: install httpd server
    shell: ps aux|grep httpd
    register: check_httpd
  - name: stdout httpd
    debug:
      msg: "{{check_httpd.stdout_lines}}"
  - name: stdout dates
    debug:
      msg: "{{show_date.stdout_lines}}"
  
  handlers:
    - name: restart httpd
      service: name=httpd state=restarted
```





```
--- 
- hosts: server1
  tasks:
  - name: show date
    command: date
    register: show_date
  - name: install httpd server
    service: name=httpd state=start
  - name: install httpd server
    shell: ps aux|grep httpd
    register: check_httpd
  - name: install httpd server
    debug:
      msg: "{{check_httpd.stdout_lines}}"
  - name: install httpd server
    debug:
      msg: "{{show_date.stdout_lines}}"
  
  handlers:
    - name: restart httpd
      service: name=httpd state=started
```

