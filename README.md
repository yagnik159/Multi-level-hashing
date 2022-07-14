![images](https://user-images.githubusercontent.com/88278946/166802651-88e8c944-52a3-4fd1-9ed2-6f29ef611f7d.png)


Table of Content



1. Introduction	

1. Screenshots

1. Conclusion














































1. Introduction:

Robert J Jenkins hash function uniformly distributes keys in various buckets. The question is why do we need to rehash the key?

For 10,00,000 data records of 17 buckets for perfect hash function, Robert J. Jenkin’s hash function places 58,823 hash values into each 17 buckets. The average case is 29411 comparisons while worst case is 58823 comparisons. 

Four-level hash table with AVL representation we can handle 58823 comparisons in Log(n) time which is 16 comparisons in worst case.

`	`**Application:**

**Lookup for IP Addresses:** The technique employed on network is to access the address of IP at quick time. Due to the increase in use of network and the desire of the users to access information at short time, attempt is made to make sure the system can access a given IP address very fast. A random number is generated in form of IP addresses from 0:0:0:0 to 125:125:125:125. These numbers serve as keys to the hash functions at-level zero, one and two hash table. Figure 4 and 5 illustrate the time to lookup for a given key. For example, looking at figure 4 with 2,000 records, it takes13203 milliseconds to lookup for a particular key at zero-level, 7250 milliseconds at one-level while 6219 milliseconds at two-level for the same key. In figure 5 with 10,000 data records, it takes 40328 milliseconds to search for a given key at zero-level, 13203 milliseconds at one-level and 8391 at twolevels. The same analysis is also applied to data records of 500 and 5,000. 


1. Screenshots:

![images](https://user-images.githubusercontent.com/88278946/166802664-f2bbf535-3305-4e27-93d5-2bf6b1fdb01e.png)

![images](https://user-images.githubusercontent.com/88278946/166802670-cdf525d6-b7f6-4651-9869-5d6ebeaef857.png)

![images](https://user-images.githubusercontent.com/88278946/166802674-3324f953-92d7-4b9d-9c52-ae12566c573f.png)




1. Conclusion:


Multilevel hash function is a really important data structure for handling a large number of keys. This data structure is used in database management systems to retrieve record data quickly. The given hash implementation is written in C++ with time to lookup for a given particular key.

Video Link:

https://drive.google.com/drive/u/1/folders/1sYB7sr4UyOaeIcSS6KGYpZ_BL59vjzpF

