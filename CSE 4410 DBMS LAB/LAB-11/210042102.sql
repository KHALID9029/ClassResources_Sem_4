--1) Customer Creation
create
(c1:CUSTOMER
{
    customer_id:102, 
    customer_name:'John', 
    phone_no:'123-456-7890',
    age:30,
    Gender:'Male',
    Country:'USA'
}),
(c2:CUSTOMER
{
    customer_id:123, 
    customer_name:'Alice', 
    phone_no:'987-654-3210',
    age:25,
    Gender:'Female',
    Country:'UK'
}),
(c3:CUSTOMER
{
    customer_id:311, 
    customer_name:'Bob', 
    phone_no:'555-555-5555',
    age:40,
    Gender:'Male',
    Country:'Canada'
})




--2) Author Creation
create
(a1:AUTHOR
{
    author_name:'J.K. Rowling',
    country:'UK'
})



--3) Book Creation
create
(b1:BOOK
{
    isbn:'1408855652',
    book_name:"Harry Potter and the Philosopher's Stone",
    genre:'Fantasy',
    published_year:1997,
    price:9.99
}),
(b2:BOOK
{
    isbn:'0439064866',
    book_name:"Harry Potter and the Chamber of Secrets",
    genre:'Fantasy',
    published_year:1998,
    price:10.99
})





--4) Create Wrote Relation
match (a:AUTHOR),(b:BOOK)
where a.author_name='J.K. Rowling' and b.isbn='1408855652'
create (a)-[r:WROTE]->(b)


match (a:AUTHOR{author_name:'J.K. Rowling'}),
(b:BOOK{isbn:'0439064866'})
create (a)-[r:WROTE]->(b)



--5) Create Book with author
CREATE
(a:AUTHOR
{
    author_name:'Stephen King',
    country:'USA'
})-[r:WROTE]->
(b:BOOK
{
    isbn:'1982102319',
    book_name:'The Shining',
    genre:'Horror',
    published_year:1977,
    price:12.99
}),
(a1:AUTHOR
{
    author_name:'Agatha Christie',
    country:'UK'
})-[r1:WROTE]->
(b1:BOOK
{
    isbn:'0062073492',
    book_name:'Murder on the Orient Express',
    genre:'Mystery',
    published_year:1934,
    price:8.99
})






--6) Create purchased Relation
match (a:CUSTOMER{customer_id:123}),(b:BOOK{isbn:'1408855652'})
create (a)-[r:PURCHASED{amount:3}]->(b)


match (a:CUSTOMER{customer_id:123}),(b:BOOK{isbn:'0439064866'})
create (a)-[r:PURCHASED{amount:1}]->(b)


match (a:CUSTOMER{customer_id:311}),(b:BOOK{isbn:'0062073492'})
create (a)-[r:PURCHASED{amount:1}]->(b)


match (a:CUSTOMER{customer_id:102}),(b:BOOK{isbn:'0062073492'})
create (a)-[r:PURCHASED{amount:1}]->(b)






--7) Create Rated Relation
match (a:CUSTOMER{customer_id:123}),(b:BOOK{isbn:'1408855652'})
create (a)-[r:RATED{rating:5,rating_date:date('2021-02-11')}]->(b)


match (a:CUSTOMER{customer_id:311}),(b:BOOK{isbn:'1408855652'})
create (a)-[r:RATED{rating:3,rating_date:date('2022-04-19')}]->(b)


match (a:CUSTOMER{customer_id:311}),(b:BOOK{isbn:'0062073492'})
create (a)-[r:RATED{rating:4,rating_date:date('2024-01-09')}]->(b)


match (a:CUSTOMER{customer_id:102}),(b:BOOK{isbn:'0062073492'})
create (a)-[r:RATED{rating:5,rating_date:date('2023-04-04')}]->(b)


match (a:CUSTOMER{customer_id:123}),(b:AUTHOR{author_name:'J.K. Rowling'})
create (a)-[r:RATED{rating:5,rating_date:date('2021-03-12')}]->(b)


match (a:CUSTOMER{customer_id:123}),(b:AUTHOR{author_name:'Stephen King'})
create (a)-[r:RATED{rating:2,rating_date:date('2023-03-18')}]->(b)









--8) Create Follow relation
match (a:CUSTOMER{customer_id:123}),(b:CUSTOMER{customer_id:311})
create (a)-[r:FOLLOWS]->(b)


match (a:CUSTOMER{customer_id:311}),(b:CUSTOMER{customer_id:123})
create (a)-[r:FOLLOWS]->(b)


match (a:CUSTOMER{customer_id:311}),(b:CUSTOMER{customer_id:102})
create (a)-[r:FOLLOWS]->(b)


match (a:CUSTOMER{customer_id:123}),(b:AUTHOR{author_name:'J.K. Rowling'})
create (a)-[r:FOLLOWS]->(b)


match (a:CUSTOMER{customer_id:311}),(b:AUTHOR{author_name:'Agatha Christie'})
create (a)-[r:FOLLOWS]->(b)


match (a:CUSTOMER{customer_id:102}),(b:AUTHOR{author_name:'Agatha Christie'})
create (a)-[r:FOLLOWS]->(b)







--10) Data Retrival

--a) Find all the ‘rated’ books node with associated the customers.
match (c:CUSTOMER)-[r:RATED]->(b:BOOK) return b


--b) Find all the ‘follows’ relation.
match f=()-[r:FOLLOWS]->() return f


--c) Find the average rating of ‘Harry Potter and the Philosopher’s Stone’.
match (c:CUSTOMER)-[r:RATED]-> (b:BOOK{book_name:"Harry Potter and the Philosopher's Stone"})
return avg(r.rating)


--(d) Find the name of the second expensive book.
match (b:BOOK) return b order by b.price Desc SKIP 1 limit 1


--(e) Find the name of customer who bought books of the authors they follow along with the amount.
match (c:CUSTOMER)-[r:PURCHASED]->(b:BOOK)<-
[r1:WROTE]-(a:AUTHOR)<-
[r2:FOLLOWS]-(c1:CUSTOMER) 
return c1.customer_name,r.amount,b.book_name


--f) Find the customer who both rated the books of J.K. Rowling and follows her.
match (c:CUSTOMER)-[r:RATED]->(b:AUTHOR{author_name:'J.K. Rowling'})<-
[r1:FOLLOWS]-(c1:CUSTOMER) return c1.customer_name


--g) Find the latest rated author
match (c:CUSTOMER)-[r:RATED]->(b:AUTHOR) return b.author_name, max(r.rating_date)


--h) Find the name of authors who write books of Mystery or Fantasy genre along with author’s rating. [hint: use optional before the MATCH which may or may not be present]
match (c:CUSTOMER)-[r:RATED]->(b:AUTHOR)<-[r1:WROTE]-(b1:BOOK)
where b1.genre='Mystery' or b1.genre='Fantasy'
return b.author_name, r.rating







--11) Data Update


--a) Add a new label playwright for ‘Agatha Christie’
match (a:AUTHOR{author_name:'Agatha Christie'}) set a:PLAYWRIGHT return a


--b) Modify the published year to 1980 for the book titled "The Shining."
match (b:BOOK{book_name:'The Shining'}) set b.published_year=1980 return b

--c) Update the relationship attribute from "rating" to "star" while retaining the same value for the rating attribute in the relationship between customers and authors.
match (c:CUSTOMER)-[r:RATED]->(b:AUTHOR) set r.star=r.rating remove r.rating return r



--12) Data Delete 


--a) Delete the author "Stephen King"
match (a:AUTHOR{author_name:'Stephen King'}) detach delete a


--b) Delete all the customer to customer ‘follows’ relation
match (c:CUSTOMER)-[r:FOLLOWS]->(c1:CUSTOMER) delete r


--c) Delete all the rating (relation) that occurred before 2022
match (c:CUSTOMER)-[r:RATED]->(b) where r.rating_date<date('2022-01-01') delete r