#!/bin/bash

if grep -qEi "(Microsoft|WSL)" /proc/version &> /dev/null
then
  env | grep -e "BASH" -e "SHELL" | wc -l
  env | grep -e "BASH" -e "SHELL" | cut -d "=" -f 1
else
  systemctl status ssh
fi
