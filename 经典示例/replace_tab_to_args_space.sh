#########################################################################
# File Name: replace_tab_to_args_space.sh
# Author: chaofei
# mail: chaofeibest@163.com
# Created Time: 2017-08-08 04:14:06
#########################################################################
#!/bin/bash

function convert_relative_path_to_absolute_path() {
  this="${0}"
  bin=`dirname "${this}"`
  script=`basename "${this}"`
  bin=`cd "${bin}"; pwd`
  this="${bin}/${script}"
}
  
function get_soft_home() {
  if [ -z "${SOFT_HOME}" ]; then
    export SOFT_HOME=`dirname "${bin}"`
  fi
}

function get_current_time() {
  CURRENT_TIME=`date +"%Y-%m-%d %H:%M:%S"`
  echo "${CURRENT_TIME}"
}

function replace_tab_to_args_space() {
  if [ -n "${1}" ]; then 
    sed -i -e "s/\t/${NUMBER_SPACE}/g" "${1}" 
    REPLACE_RESULT=$?
    if [ "${REPLACE_RESULT}" -eq 0 ]; then
      echo -e "`get_current_time` deal tab to [${NUMBER_SPACE}] with file [${1}]  -- \033[32mOK\033[0m"
    else
      echo -e "`get_current_time` deal tab to [${NUMBER_SPACE}] with file [${1}]  -- \033[31mFAILED\033[0m"
    fi
    if [ -n "${3}" ]; then
      shift
      replace_tab_to_args_space $*
    fi
  else
    usage
  fi
}

function usage() {
  echo "Usage:${this} file
Example:
   ${this} functions.sh
   ${this} *.sh
"
}

convert_relative_path_to_absolute_path
get_soft_home
TWO_SPACE="  "
FOUR_SPACE="    "
NUMBER_SPACE="${TWO_SPACE}"
#NUMBER_SPACE="${FOUR_SPACE}"
replace_tab_to_args_space $*
