# with open('pp/words.txt','w') as file:
#     file.write("Hello, this is an example text file.\n")
#     file.write("You can add more lines here.\n")
#     file.write("Feel free to modify it as needed.\n")
import csv
words=[]
dic={}
with open('pp/words.txt','r') as file:

    lines=file.read()
    print(lines)
    words=lines.split()
    print(words)
for i in words:
    count=1
    dic[i]=count
    words.remove(i)
    for j in words:
        if j==i:
            dic[i]=count+1
            words.remove(i)
print(dic)


with open('pp/words.csv','w') as file:
    write=csv.writer(file)
    for i in dic:
        write.writerow([i,dic[i]])