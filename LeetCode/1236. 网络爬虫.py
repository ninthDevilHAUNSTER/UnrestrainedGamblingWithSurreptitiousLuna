# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl, htmlParser):
        # 这用Python不是秒杀题
        rec_set = {startUrl}
        rec_list = [startUrl]
        host_name = 'http://' + startUrl.split('/')[2]

        for url in rec_list:
            a = htmlParser.getUrls(url)
            for i in a:
                if i.startswith(host_name) and i not in rec_list:
                    rec_set.add(i)
                    rec_list.append(i)
        return rec_list