DROP TABLE IF EXISTS users CASCADE;
DROP TABLE IF EXISTS authors CASCADE;
DROP TABLE IF EXISTS user_lists CASCADE;
DROP TABLE IF EXISTS publishers CASCADE;
DROP TABLE IF EXISTS books CASCADE;
DROP TABLE IF EXISTS book_authors;
DROP TABLE IF EXISTS list_books;
DROP TABLE IF EXISTS ratings;
DROP TABLE IF EXISTS read_list;
DROP TABLE IF EXISTS reviews;
DROP TABLE IF EXISTS trade_have;
DROP TABLE IF EXISTS trade_want;
DROP TABLE IF EXISTS user_followers;


CREATE TABLE users (
  user_id SERIAL PRIMARY KEY,   				-- Auto-generated ID
  name TEXT NOT NULL,           				-- Name (First/Last)
  DOB DATE NOT NULL,           				  -- Basic DOB
  zipcode INT,        				          -- (optional zip)
  intro TEXT,         				          -- basic block of intro text (optional)
  trade_contact TEXT NOT NULL,  				-- contact info (phone#)
  join_date DATE NOT NULL default CURRENT_DATE,	-- Auto saved date of creation
  user_name TEXT NOT NULL UNIQUE ,     				  -- Username (Unique)
  p_word TEXT NOT NULL          				-- pw
);

CREATE TABLE authors(
  author_id SERIAL PRIMARY KEY,         -- Auto-generated ID
  author_name TEXT NOT NULL             -- Author name
);                                      -- Further fields could be added, such as website

CREATE TABLE publishers (
  publisher_id SERIAL PRIMARY KEY,      -- Auto-generated ID
  publisher_name TEXT NOT NULL          -- Publisher name
);                                      -- Further fields could be added, such as website

CREATE TABLE books (
  book_id SERIAL PRIMARY KEY,        -- Auto-generated ID
  title TEXT NOT NULL,               -- Title of book
  subject TEXT NOT NULL,             -- Basic tag for
  publisher_id INT REFERENCES publishers (publisher_id),
  publication_date DATE,             -- Date of publication (optional)
  page_count INT,                    -- page count (optional)
  ISBN INT,                          -- ISBN (optional)
  short_desc TEXT                    -- short description of the book (optional)
);

CREATE TABLE trade_have (
  tradehave_id SERIAL PRIMARY KEY,                -- auto-generated trade_id
  book_id INT NOT NULL REFERENCES books(book_id), -- available book_id
  user_id INT NOT NULL REFERENCES users(user_id), -- user who posted their book is available
  num_avail INT NOT NULL default 1,               -- number of copies available
  added_date DATE NOT NULL default CURRENT_DATE   -- date of posting
);


CREATE TABLE trade_want (
  book_id INT NOT NULL REFERENCES books(book_id), -- desired book
  user_id INT NOT NULL REFERENCES users(user_id), -- user looking for book
  added_date DATE NOT NULL default CURRENT_DATE,  -- date of creation
  PRIMARY KEY (book_id,user_id)
);

CREATE TABLE ratings (
  book_id INT NOT NULL REFERENCES books(book_id), -- book's id
  user_id INT NOT NULL REFERENCES users(user_id), -- rater's id
  rating INT NOT NULL,                            -- the rating
  rating_date DATE NOT NULL default CURRENT_DATE, -- date of rating
  PRIMARY KEY (book_id,user_id)                   -- each user may only have one rating per book
);

CREATE TABLE reviews(
  book_id INT NOT NULL REFERENCES books(book_id), -- id of book being reviewed
  user_id INT NOT NULL REFERENCES users(user_id), -- reviewer id
  review TEXT NOT NULL,                           -- the review
  post_date DATE NOT NULL default CURRENT_DATE,   -- post date
  PRIMARY KEY (book_id,user_id)                   -- each user may only have one review per book
);

CREATE TABLE book_authors(
  author_list SERIAL PRIMARY KEY,                 -- Auto-generated list ID
  book_id INT NOT NULL REFERENCES books(book_id), -- book id for this list
  author_id INT NOT NULL REFERENCES authors(author_id), -- id of author for book
  appear_num INT NOT NULL                         -- number order of appearance
);

CREATE TABLE user_lists(
  list_id SERIAL PRIMARY KEY,                     -- Auto-generated List ID
  list_name TEXT NOT NULL,                        -- name of list
  user_id INT NOT NULL REFERENCES users(user_id), -- creator of list
  create_date DATE NOT NULL default CURRENT_DATE  -- date of creation
);

CREATE TABLE list_books(
  list_books SERIAL PRIMARY KEY,                  --
  list_id INT NOT NULL REFERENCES user_lists(list_id),-- list to which book is added
  book_id INT NOT NULL REFERENCES books(book_id), -- book being added
  added_date DATE NOT NULL  default CURRENT_DATE  -- date book was added to list
);


CREATE TABLE read_list(
  read_id SERIAL PRIMARY KEY,
  book_id INT NOT NULL REFERENCES books(book_id), -- bookid
  user_id INT NOT NULL REFERENCES users(user_id), -- userid
  num_read INT default 1,                         -- number of times read
  begin_date DATE default CURRENT_DATE,           -- date user began reading book
  finish_date DATE                                -- date user finished reading book
);


CREATE TABLE user_followers(
  following_user INT NOT NULL REFERENCES users(user_id), -- User who chose to follow
  followed_user INT NOT NULL REFERENCES users(user_id),  -- User being followed
  PRIMARY KEY (following_user, followed_user)            -- this is a unique combination
);


-- Indices
CREATE INDEX trade_have_books_idx ON trade_have (book_id);
CREATE INDEX trade_have_users_idx ON trade_have (user_id);
CREATE INDEX trade_want_books_idx ON trade_want (book_id);
CREATE INDEX trade_want_users_idx ON trade_want ( user_id);
CREATE INDEX ratings_books_idx ON ratings (book_id);
CREATE INDEX ratings_users_idx ON ratings (user_id);
CREATE INDEX reviews_books_idx ON reviews (book_id);
CREATE INDEX reviews_users_idx ON reviews (user_id);
CREATE INDEX books_publishers_idx ON books (publisher_id);
CREATE INDEX book_authors_books_idx ON book_authors (book_id);
CREATE INDEX book_author_author_idx ON book_authors (author_id);
CREATE INDEX list_books_list_idx ON list_books (list_id);
CREATE INDEX list_books_book_idx ON list_books (book_id);
CREATE INDEX user_lists_user_idx ON user_lists (user_id);
CREATE INDEX read_list_book_idx ON read_list (book_id);
CREATE INDEX read_list_user_idx ON read_list (user_id);
CREATE INDEX user_followers_user_idx ON user_followers (following_user);