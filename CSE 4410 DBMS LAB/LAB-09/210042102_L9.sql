db.posts.updateMany(
    {content: {$in:["Hudai Post","Post 2","Post 3"]}},
    {$push:{liker:{$each:["Khalid","Shuvro","Hamim"]}}}
);


--d) Add at least two comments for two posts with the commenters
db.posts.updateMany(
    {content: {$in:["Hudai Post","Post 2"]}},
    {$push:{comments:{$each:[{commenter:"Khalid",comment:"Agun"},{commenter:"Shuvro",comment:"Good Post"}]}}}
);


-- Display the total number of posts
db.posts.find().count();

--Display the most recent to oldest posts along with their poster(s).
db.posts.find({},{poster:1}).sort({date:-1});

--Show all the posts that were created from yesterday
const start = new Date();
start.setHours(0,0,0,0);
start.setDate(start.getDate()-1);

const end = new Date();
end.setHours(23,59,59,999);
end.setDate(end.getDate()-1);

db.posts.find({date:{$gte:start,$lte:end}});


--Show all the users who are following more than 3 users.
db.users.find({following:{$size:{$gt:3}}});

--Show all the users who were born within 1990-2000.
db.users.find({dob:{$gte:new Date("1990-01-01"),$lte:new Date("2000-12-31")}});


--Show three profiles that were created the earliest
db.users.find().sort({date:1}).limit(3);

--Show all the posts where commenter "ABC" commented
db.posts.find({"comments.commenter":"ABC"});


--Show the user’s detail who posted "Life is too good".
db.users.find({name:db.posts.findOne({content:"Life is too good"}).poster});

--Delete the users who don’t have any work phone number.
db.users.deleteMany({work_phone:{$exists:false}});