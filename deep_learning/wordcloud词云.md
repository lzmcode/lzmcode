# - * - coding: utf - 8 -*-

from os import path
from scipy.misc import imread
import matplotlib.pyplot as plt
import jieba
# jieba.load_userdict("txt\userdict.txt")
# ����û��ʿ�Ϊ���ʵ�,ԭ�ʵ��Ϊ�����ʵ�
from wordcloud import WordCloud, ImageColorGenerator

# ��ȡ��ǰ�ļ�·��
# __file__ Ϊ��ǰ�ļ�, ��ide�����д��лᱨ��,�ɸ�Ϊ
d = path.dirname('.')

stopwords = {}
isCN = 1 #Ĭ���������ķִ�
back_coloring_path = 'heart.jpg' # ���ñ���ͼƬ·��
text_path = 'xy.txt' #����Ҫ�������ı�·��
font_path = 'simhei.ttf' # Ϊmatplotlib������������·��û
stopwords_path = 'stopwords.txt' # ͣ�ôʴʱ�
imgname1 = "WordCloudDefautColors.png" # �����ͼƬ����1(ֻ���ձ���ͼƬ��״)
imgname2 = "WordCloudColorsByImg.png"# �����ͼƬ����2(��ɫ���ձ���ͼƬ��ɫ��������)

my_words_list = ['·����'] # �ڽ�͵Ĵʿ�������´�

back_coloring = imread(path.join(d, back_coloring_path))# ���ñ���ͼƬ

# ���ô�������
wc = WordCloud(font_path=font_path,  # ��������
               background_color="white",  # ������ɫ
               max_words=2000,  # ������ʾ��������
               mask=back_coloring,  # ���ñ���ͼƬ
               max_font_size=100,  # �������ֵ
               random_state=42,
               width=1000, height=860, margin=2,# ����ͼƬĬ�ϵĴ�С,�������ʹ�ñ���ͼƬ�Ļ�,��ô�����ͼƬ��С���ᰴ�����С����,marginΪ�����Ե����
               )

# ����Լ��Ĵʿ�ִ�
def add_word(list):
    for items in list:
        jieba.add_word(items)

add_word(my_words_list)

text = open(path.join(d, text_path)).read()

def jiebaclearText(text):
    mywordlist = []
    seg_list = jieba.cut(text, cut_all=False)
    liststr="/ ".join(seg_list)
    f_stop = open(stopwords_path)
    try:
        f_stop_text = f_stop.read( )
        #f_stop_text=unicode(f_stop_text,'utf-8')
    finally:
        f_stop.close( )
    f_stop_seg_list=f_stop_text.split('\n')
    for myword in liststr.split('/'):
        if not(myword.strip() in f_stop_seg_list) and len(myword.strip())>1:
            mywordlist.append(myword)
    return ''.join(mywordlist)

if isCN:
    text = jiebaclearText(text)

# ���ɴ���, ������generate����ȫ���ı�(wordcloud�����ķִ�֧�ֲ���,�����������ķִ�),Ҳ�������Ǽ���ô�Ƶ��ʹ��generate_from_frequencies����
wc.generate(text)
# wc.generate_from_frequencies(txt_freq)
# txt_freq����Ϊ[('��a', 100),('��b', 90),('��c', 80)]
# �ӱ���ͼƬ������ɫֵ
image_colors = ImageColorGenerator(back_coloring)

plt.figure()
# ���´�����ʾͼƬ
plt.imshow(wc)
plt.axis("off")
plt.show()
# ���ƴ���

# ����ͼƬ
wc.to_file(path.join(d, imgname1))

image_colors = ImageColorGenerator(back_coloring)

plt.imshow(wc.recolor(color_func=image_colors))
plt.axis("off")
# ���Ʊ���ͼƬΪ��ɫ��ͼƬ
plt.figure()
plt.imshow(back_coloring, cmap=plt.cm.gray)
plt.axis("off")
plt.show()
# ����ͼƬ
wc.to_file(path.join(d, imgname2))