# -*- coding: utf-8 -*-
import requests
from bs4 import BeautifulSoup

url = "https://www.tfd.metro.tokyo.lg.jp/kb/pc/list201.htm" #八王子市の病院
request = requests.get(url)

soup = BeautifulSoup(requests.data, 'html.parser')
title_tag = soup.title
title = title_tag.string
print(title_tag)
print(title)