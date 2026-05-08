#!/bin/bash

# 1. إنشاء ملف تقرير بتاريخ اليوم داخل مجلد notes
filename="notes/report_$(date +%Y-%m-%d).txt"
touch $filename

# 2. إضافة المعلومات المطلوبة للملف
echo "اسم المستخدم الحالي: $(whoami)" >> $filename
echo "المسار الحالي: $(pwd)" >> $filename
echo "عدد الملفات داخل data هو: $(ls data | wc -l)" >> $filename

# 3. طباعة عبارة نجاح عند نهاية التنفيذ
echo "تم تنفيذ السكربت بنجاح وإنشاء التقرير!"