import tkinter as tk
import requests
import random
import json
from hashlib import md5


root = tk.Tk()  # 生成一个窗口
root.title('翻译')  # 为窗口起个名字
root.geometry('500x500')  # 设置窗口大小

InputLabel = tk.Label(root, text='输入中文：')  # text为标签上的内容    Label
InputLabel.grid(row=0, sticky='W')  # 这里分为两步，一步设置元素，一步放置位置
InputText = tk.Text(root, width=50, height=10)  # 放在窗口上，设置宽，高     Text
InputText.grid(row=5)  # 设置位置

PrintLabel = tk.Label(root, text='翻译：')  # text为标签上的内容    Label
PrintLabel.grid(row=6, sticky='W')  # 这里分为两步，一步设置元素，一步放置位置
PrintText = tk.Text(root, width=50, height=10)  # 放在窗口上，设置宽，高     Text
PrintText.grid(row=7)


def insert_point():
    query = InputText.get("1.0", "1.end")  # 获取输入的信息
    #query = "hello"
    # t.insert("insert",var) #参数1：插入方式，参数2：插入的数据
    # Set your own appid/appkey.
    appid = '20200505000440298'
    appkey = 'dfWONmTro6PYpECT1KGA'

    # For list of language codes, please refer to `https://api.fanyi.baidu.com/doc/21`
    from_lang = 'en'
    to_lang = 'zh'

    endpoint = 'http://api.fanyi.baidu.com'
    path = '/api/trans/vip/translate'
    url = endpoint + path

    #query = str(input("请输入翻译的内容："))

    # Generate salt and sign

    def make_md5(s, encoding='utf-8'):
        return md5(s.encode(encoding)).hexdigest()

    salt = random.randint(32768, 65536)
    sign = make_md5(appid + query + str(salt) + appkey)

    # Build request
    headers = {'Content-Type': 'application/x-www-form-urlencoded'}
    payload = {'appid': appid, 'q': query, 'from': from_lang,
               'to': to_lang, 'salt': salt, 'sign': sign}

    # Send request
    r = requests.post(url, params=payload, headers=headers)
    result = r.json()

    # Show response
    #print(json.dumps(result, indent=4, ensure_ascii=False))
    #print("翻译结果：", result['trans_result'][0]['dst'])
    # print(result['trans_result'][0]['dst'])

    PrintText.insert("insert", result['trans_result'][0]['dst'])


TranButton = tk.Button(root, text="insert point",
                       width=15, height=2, command=insert_point)
TranButton.grid(row=8)


tk.mainloop()
