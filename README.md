# Mupdf-AndroidStudio

移植Mupdf工程到AndroidStudio.

###mupdf版本`1.8`

###AndroidStudio版本必须高于`2.2`.

---

SDK版本选到9时编译会产生错误。 这里用的15. 其他版本没有试验。
undefined reference to 'sigsetjmp'

为防止Studio内存溢出卡死，可提前加高Studio内存。 这里为8G内存。

-Xms512m
-Xmx8192m
-XX:MaxPermSize=700m
-XX:ReservedCodeCacheSize=480m

---

swjjxyxty@gmail.com
