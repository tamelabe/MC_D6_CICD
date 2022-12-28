#!/bin/bash

DATE=$(date | awk '{print ($2,$3,$4, $5)}')

BOT_TOKEN=5736720897:AAHxhJBxGDUd3kTwQPIh9lGwo4fYCe9eRqI
CHAT_ID=201975782

CI="     Failed  ❌"
CD="    Failed  ❌"

if [[ $1 -eq 1 ]]; then
    CI="     Passed  ✅"
    CD="    Not started yet..."
elif [[ $1 -eq 2 ]]; then
    CI="     Passed  ✅"
    CD="    Passed  ✅"
fi

TEXT="Date: $DATE%0ACI Status:$CI%0ACD Status:$CD"
# TIME="10"
# URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
# TEXT="Hello World!"
# # TEXT="Deploy status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s -X POST https://api.telegram.org/bot$BOT_TOKEN/sendMessage -d chat_id=$CHAT_ID -d text="$TEXT"