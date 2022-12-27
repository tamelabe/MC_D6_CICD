#!/bin/bash

BOT_TOKEN=5736720897:AAHxhJBxGDUd3kTwQPIh9lGwo4fYCe9eRqI

# TIME="10"
# URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
# TEXT="Hello World!"
# # TEXT="Deploy status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s -X POST https://api.telegram.org/bot$BOT_TOKEN/sendMessage -d chat_id=201975782 -d text="Ппривет, Эля!"