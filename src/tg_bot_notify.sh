#!/bin/bash
source ./src/secure.sh

DATE=$(date | awk '{print ($2,$3,$4, $5)}')

# BOT_TOKEN=5736720897:AAHxhJBxGDUd3kTwQPIh9lGwo4fYCe9eRqI
# CHAT_ID=201975782

CI="     Failed  ❌"
CD="    Not started"

if [[ $1 -eq 1 ]]; then
    CI="     Passed  ✅"
    CD="    Not started yet..."
elif [[ $1 -eq 2 ]]; then
    CI="     Passed  ✅"
    CD="    Passed  ✅"
elif [[ $1 -eq 3 ]]; then
    CI="     Passed  ✅"
    CD="    Failed  ❌"
fi

TEXT="Date: $DATE%0ACI Status:$CI%0ACD Status:$CD"

curl -s -X POST https://api.telegram.org/bot$BOT_TOKEN/sendMessage -d chat_id=$CHAT_ID -d text="$TEXT"