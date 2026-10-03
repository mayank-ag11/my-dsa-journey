#!/bin/bash

for dir in */
do
    NEW_NAME="${dir%*/}.js"
    cp "${dir}index.js" "./${NEW_NAME}"
    
    # echo "${NEW_NAME}"
    
    # dir=${dir%*/}
    # echo "${dir##*/}"
done

# After copying the files, deleting the folders by
# rm -r */
