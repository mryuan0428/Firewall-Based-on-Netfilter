 - 开发环境：
	 - 操作系统：Ubuntu 15.10
	 - 内核版本：4.2.0-16-generic 
	 - 开发软件：Qt 5.9.0
	 - 编译器：gcc version 5.2.1

 - 项目内容：
```
    |--WJ_firewall文件夹（应用层：使用Qt开发的用户界面）
    	|--……
    |--build-WJ_firewall-Desktop_Qt_5_9_0_GCC_64bit-Debug文件夹（Qt编译产生的可执行程序，sudo ./WJ_firewall 可运行）
        |--WJ_firewall（可执行程序）
        |--……
    |--process&module文件夹
        |--dataset.py -- 包含大量数据处理函数，如facility_process(),dataset()
            |--facility_process()函数 -- 将数据集中关于设备的描述关键词分类
            |--dataset()函数 -- 数据集接口，返回dict类型的数据集
        |--dataset3文件夹 -- facility_process()处理过后的数据集
        |--建模过程.docx -- 简述建模过程，其中说明了process&module文件夹下tocsv.py，data_c.csv……文件的意义
        |--result_pictures文件夹 -- 建模过程中各个模型的回归曲线
        |--……其余文件，包含训练、测试数据集，建模文件，模型… 在建模过程.docx中有说明
```

```
dataset()函数用法说明：
dataset(*, src='./data2', dst='./dataset', load_from_source=False)
```

 - Keyword arguments:
    * `src` -- `str`, source data path
    * `dst` -- `str`, dataset path
    * `load_from_source` -- `bool`, flag if load from source (`False` in default)

    - Notes:
        * `Info` turn dictionaries into object-like instances
            - inherits from `dict` type
            - iterable, and support all functions as `dict`
            - immutable, thus cannot set or delete attributes after initialisation
            - `infotodict` -- reverse `Info` object into `dict` type
        * `Dataset` object herits from `tuple`
            ```python
            # returns from `dataset` function
            >>> data = dataset()
            # subscriptable as normal tuples
            >>> data[0]
            >>> data[1:10]
            # or to fetch certain keys
            >>> data[1, 'apt', 'lift']
            Info(apt=(2,), lift=(1,))
            >>> data[1:3, 'price', 'average']
            Info(price=(2600000.0, 3080000.0), average=(44636, 36032))
            ```
