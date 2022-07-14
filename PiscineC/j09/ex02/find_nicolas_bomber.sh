(grep -i -e '\(bomber[[:blank:]]nicolas\)' $1 && grep -i -e '\(nicolas[[:blank:]]bomber\)' $1) | wc -l | tr -d ' '
