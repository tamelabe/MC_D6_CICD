# Basic CI/CD

Development of a simple **CI/CD** for the *SimpleBashUtils* project. Building, testing, deployment.

## Part 1. Настройка gitlab-runner

Установка gitlab-runner
![image](src/resources/1.1.png)
![image](src/resources/1.2.png)
![image](src/resources/1.3.png)
![image](src/resources/1.4.png)

Регистрация gitlab-runner
![image](src/resources/1.5.png)

## Part 2. Сборка

Создание пайплайна для сборки - gitlab-ci.yml
![image](src/resources/)

Статус
![image](src/resources/2.2.png)

Работа стадии сборки
![image](src/resources/2.3.png)

## Part 3. Тест кодстайла

Добавление стадии в пайплайн
![image](src/resources/3.1.png)

Статус
![image](src/resources/3.2.png)

Работа стадии кодстайла (fail/passed)
![image](src/resources/3.3.png)
![image](src/resources/3.4.png)

## Part 4. Интеграционные тесты

Добавление стадии в пайплайн
![image](src/resources/4.1.png)

Добавление в скрипт с тестами выхода с кодом 1, чтобы зайейлить пайплайн
![image](src/resources/4.2.png)

Статус
![image](src/resources/4.3.png)

Работа стадии интеграционного тестирования (fail/passed)
![image](src/resources/4.4.png)
![image](src/resources/4.5.png)

## Part 5. Этап деплоя

Конфигурация сети для первой виртуальной машины
![image](src/resources/5.1.png)

Пингование 2 виртуальных машин между собой
![image](src/resources/5.2.png)
![image](src/resources/5.3.png)

Далее создал ssh ключ для пользователя gitlab-runner и импортировал во вторую виртуалку через команду `ssh-copy-id`, чтобы не просил пароль при подкючении

Прописал в пайплайн стадию деплоя, в скрипте прописал импорт собранного файла во 2 виртуалку и перемещение в требуемую директорию:
![image](src/resources/5.4.png)
![image](src/resources/5.5.png)

Тестирование стадии:
![image](src/resources/5.6.png)

В случае фейла (специально указал не тот файл в скрипте)
![image](src/resources/5.7.png)

ДАМПЫ ВИРТУАЛОК сохранены здесь: [ссылка](https://drive.google.com/drive/folders/1iHQ_3LbIr3rnZ2zXqUO5_BGj5M0jcR3X?usp=share_link)

## Part 6. Дополнительно. Уведомления

Зарегистрировал бота, получил токен, затем нашел `chat_id`
![image](src/resources/6.1.png)

Написал скрипт для постинга сообщений
![image](src/resources/6.2.png)

Изменил `gitlab-ci.yml` для обработки зафейленного пайплайна
![image](src/resources/6.3.png)

Уведомления в телеграм-боте:
![image](src/resources/6.4.png)

Пайплайн:
![image](src/resources/6.4.1.png)

Имя бота: `@tamelabe_cicd_bot`
![image](src/resources/6.5.png)

