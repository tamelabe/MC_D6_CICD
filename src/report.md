## Part 1. Настройка gitlab-runner

Установка gitlab-runner
![image](resources/1.1.png)
![image](resources/1.2.png)
![image](resources/1.3.png)
![image](resources/1.4.png)

Регистрация gitlab-runner
![image](resources/1.5.png)

## Part 2. Сборка

Создание пайплайна для сборки - gitlab-ci.yml
![image](resources/)

Статус
![image](resources/2.2.png)

Работа стадии сборки
![image](resources/2.3.png)

## Part 3. Тест кодстайла

Добавление стадии в пайплайн
![image](resources/3.1.png)

Статус
![image](resources/3.2.png)

Работа стадии кодстайла (fail/passed)
![image](resources/3.3.png)
![image](resources/3.4.png)

## Part 4. Интеграционные тесты

Добавление стадии в пайплайн
![image](resources/4.1.png)

Добавление в скрипт с тестами выхода с кодом 1, чтобы зайейлить пайплайн
![image](resources/4.2.png)

Статус
![image](resources/4.3.png)

Работа стадии интеграционного тестирования (fail/passed)
![image](resources/4.4.png)
![image](resources/4.5.png)

## Part 5. Этап деплоя

Конфигурация сети для первой виртуальной машины
![image](resources/5.1.png)

Пингование 2 виртуальных машин между собой
![image](resources/5.2.png)
![image](resources/5.3.png)

Далее создал ssh ключ для пользователя gitlab-runner и импортировал во вторую виртуалку через команду `ssh-copy-id`, чтобы не просил пароль при подкючении

Прописал в пайплайн стадию деплоя, в скрипте прописал импорт собранного файла во 2 виртуалку и перемещение в требуемую директорию:
![image](resources/5.4.png)
![image](resources/5.5.png)

Тестирование стадии:
![image](resources/5.6.png)

В случае фейла (специально указал не тот файл в скрипте)
![image](resources/5.7.png)

ДАМПЫ ВИРТУАЛОК сохранены здесь: [ссылка](https://drive.google.com/drive/folders/1iHQ_3LbIr3rnZ2zXqUO5_BGj5M0jcR3X?usp=share_link)

## Part 6. Дополнительно. Уведомления

