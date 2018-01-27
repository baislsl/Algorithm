from bs4 import BeautifulSoup
import urllib2
def get_begin_data(url):
    headers = {
        'ser-Agent': '',
        'Cookie': ''
    }
    request = urllib2.Request(url, headers=headers)
    web_data = urllib2.urlopen(request)
    soup = BeautifulSoup(web_data, 'html.parser')
    results = soup.select('table > tr > td > a')
    answers = soup.select('table > tr > td > span')
    index = 0
    datas = []
    for result in results:
        if index == 0:
            data = {
                'link': result.get('href')
            }
            index += 1
        elif index == 1:
            data['title'] = result.get_text()
            datas.append(data)
            index += 1
        elif index == 2:
            index += 1
        else:
            index = 0
    index = 0
    for answer in answers:
        if answer.get('class') != None:
            datas[index]['answer'] = answer.get('class')
            index += 1
    return datas
def anly_data(datas):
    linkList = []
    for data in datas:
        if data['answer'] == [u'submitRes-3']:
            link = {
                'url':'https://www.patest.cn'+data['link'] + '/source',
                'title':data['title']
            }
            linkList.append(link)
    return linkList
def save_file(linkList):
    headers = {
        'ser-Agent': '',
        'Cookie': ''
    }
    for link in linkList:
        request = urllib2.Request(link['url'], headers=headers)
        web_data = urllib2.urlopen(request)
        soup = BeautifulSoup(web_data, 'html.parser')
        code = soup.select('#sourceCode')
        file = open(link['title']+'.cpp', 'w')
        for i in code:
            file.write(i.get_text().encode('utf-8'))
        file.close()
if __name__ == '__main__':
    datas = []
    for page_number in range(1, 12):
        url = 'https://www.patest.cn/contests/pat-b-practise/submissions?page={}&self=true'.format(page_number)
        datas = get_begin_data(url)
        linkList = anly_data(datas)
        save_file(linkList)



