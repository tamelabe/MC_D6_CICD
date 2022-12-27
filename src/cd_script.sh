scp ./src/cat/s21_cat tamelabe1@10.0.2.4:/home/tamelabe
ssh tamelabe1@10.0.2.4 'cat pass.txt | sudo -S mv /home/tamelabe/s21_cattt /usr/local/bin/'