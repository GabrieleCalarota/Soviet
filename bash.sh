#!/bin/bash

echo "# Soviet" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/GabrieleCalarota/Soviet.git
git push -u origin master

