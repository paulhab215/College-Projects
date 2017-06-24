from flask import Flask,session, request, flash, url_for, redirect, render_template, abort ,g

import flask
import easypg
import psycopg2
import psycopg2.extras 
app = flask.Flask('SM1')

#Connect to db
conn=psycopg2.connect("dbname = 'cs4332sm1' user='postgres' host='localhost' password = 'cs4332'")
cur = conn.cursor(cursor_factory=psycopg2.extras.DictCursor)

#global functions
def find_user_query(username):
    cur.execute("SELECT * FROM users WHERE user_name = (%s)",(username,))
    username = cur.fetchone()
    return username

def find_user_name(uid):
    cur.execute("SELECT user_name FROM users WHERE user_id = (%s)",(uid,))
    username = cur.fetchone()
    return username[0]

def find_user_id(username):
    cur.execute("SELECT user_id FROM users WHERE user_name = (%s)",(username,))
    uid_find= cur.fetchone()
    print uid_find
    return uid_find[0]

@app.route('/')
def home_redirect():
    return redirect(url_for('login'))

#login
@app.route('/login',methods=['GET','POST'])
def login():
    if request.method == 'GET':
        return render_template('Login.html')
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        cur.execute("SELECT CASE WHEN EXISTS (SELECT *FROM users WHERE (user_name = %s) AND (users.p_word = %s))THEN CAST(1 AS BIT) ELSE CAST(0 AS BIT) END",(username,password,))
        check = cur.fetchone()
	if check[0] == '1':
		global remember_me 
		remember_me = find_user_id(username)
		print remember_me
		return redirect(url_for('home', username=username))
	else: 
		return redirect(url_for('login')) 


#forgot password
@app.route('/forgot',methods=['GET','POST'])
def forgot():
    if request.method == 'GET':
        return render_template('Forgot.html')
    if request.method == 'POST':
        username = request.form['username']
        cur.execute("SELECT * FROM users WHERE user_name=%s", (str(username),))
        check = cur.fetchone()
        if check is not None:
               cur.execute("UPDATE users SET (name, email, user_name, DOB, zipcode, bio, trade_contact, p_word) = ($$" + str(check[0]) + "$$,$$" + str(check[1]) + "$$,$$" + str(check[2]) + "$$,$$" + str(check[3]) + "$$,$$" + str(check[4]) + "$$,$$" + str(check[5]) + "$$,$$" +str(check[6]) + "$$,$$" + str(check[1]) +"$$)")
               cur.execute("COMMIT")
               return redirect(url_for('login'))
        else:
               return "Username not found"
        
#ProfileRegistration
@app.route('/ProfileReg' ,methods =[ 'GET', 'POST'])
def profile_reg():
    if request.method == 'GET':
        return render_template('ProfileReg.html')
    if request.method == 'POST':
        name = request.form['name']
        username = request.form['username']
        password = request.form['password']
        email = request.form['email']
        dob = request.form['dob']
        zipcode= request.form['zipcode']
        contact = request.form['contact']
        bio = request.form['bio']

        cur.execute("INSERT INTO users( name, email, user_name, DOB, zipcode, bio, trade_contact, p_word) VALUES (%s,%s, %s,%s,%s,%s, %s, %s)", (name, email, username, dob, zipcode, bio, contact, password,))
        cur.execute("COMMIT")
        return redirect(url_for('login'))
        

#home
@app.route('/home/<username>')
def home(username):
   # with easypg.cursor() as cur
    uid=find_user_id(username)
    print uid
    cur.execute("SELECT user_name, name, user_id FROM users WHERE user_id = " + str(uid))
    sql_user = cur.fetchall()
    print sql_user
    #print sql_user.user_name

    cur.execute("SELECT user_id, user_name, book_id, title, post_date, review FROM users JOIN reviews USING(user_id) JOIN user_followers ON(user_id = followed_user) JOIN books USING (book_id) WHERE following_user = " + str(uid) + " ORDER BY post_date DESC LIMIT 20")
    sql_reviews = cur.fetchall()

    cur.execute("SELECT trade_have.user_id,user_name,book_id, title,num_avail FROM trade_want JOIN trade_have USING (book_id) JOIN users ON (trade_have.user_id = users.user_id) JOIN books USING (book_id) WHERE trade_want.user_id = "+ str(uid))
    sql_trades = cur.fetchall()

    cur.execute("SELECT user_id, user_name, book_id, title, rating_date, rating FROM users JOIN ratings USING(user_id) JOIN user_followers ON(user_id = followed_user) JOIN books USING (book_id) WHERE following_user = " + str(uid) + " ORDER BY rating_date DESC LIMIT 20")
    sql_ratings = cur.fetchall()

    cur.execute("SELECT user_id, user_name, book_id, title, added_date, list_id, list_name FROM list_books JOIN user_lists USING (list_id) JOIN user_followers ON (user_id=followed_user) JOIN books USING (book_id) JOIN users USING (user_id) WHERE following_user = " + str(uid) + " ORDER BY added_date DESC LIMIT 20")
    sql_lists = cur.fetchall()

    cur.execute("SELECT user_id, user_name, book_id, title, finish_date, coalesce(num_read, 0) FROM users JOIN read_list USiNG(user_id) JOIN user_followers ON(user_id = followed_user) JOIN books USING (book_id) WHERE following_user = " + str(uid) + " ORDER BY finish_date DESC LIMIT 20")
    sql_reads = cur.fetchall()

    return flask.render_template('HomePage.html', user=sql_user, reviews=sql_reviews, ratings=sql_ratings, lists=sql_lists, reads=sql_reads,trades =sql_trades)

#ProfilePage
@app.route('/user/<uid>',methods =[ 'GET', 'POST'])
def user_details(uid):
	if request.method == 'GET':
		with easypg.cursor() as cur:
			cur.execute("SELECT * FROM users WHERE user_id = " + str(uid))
			sql_user = cur.fetchall()

			cur.execute("SELECT LIST_ID,LIST_NAME,CREATE_DATE,COUNT(BOOK_ID) FROM user_lists LEFT JOIN list_books USING (list_id) WHERE user_id = "+ str(uid) +" GROUP BY LIST_NAME,CREATE_DATE,LIST_ID ORDER BY CREATE_DATE DESC")
			sql_lists = cur.fetchall()
        
			cur.execute("SELECT COUNT(distinct book_id) FROM list_books JOIN user_lists USING (list_id) WHERE user_id = " + str(uid))
			sql_stats_lists = cur.fetchall()
        
			cur.execute("SELECT SUM(num_read) FROM read_list WHERE user_id = " + str(uid))
			sql_stats_read = cur.fetchall()
        
			cur.execute("SELECT count(DISTINCT num_read) FROM read_list WHERE user_id = " + str(uid))
			sql_stats_unique = cur.fetchall()
        
			cur.execute("SELECT SUM(COALESCE(page_count,0)) FROM books JOIN read_list USING (book_id) WHERE user_id = " + str(uid))
			sql_stats_pages = cur.fetchall()
        
			cur.execute("SELECT ROUND(EXTRACT(year from finish_date)::numeric,0) as yyyy, SUM(COALESCE(num_read,0)) as numRead, SUM(COALESCE(page_count,0)) as pagesRead FROM books JOIN read_list USING (book_id) WHERE user_id ="  + str(uid)+" GROUP BY 1 ORDER BY yyyy desc")
			sql_stats_years = cur.fetchall()
        
			cur.execute("SELECT user_id,name FROM user_followers JOIN users ON (followed_user = user_id) WHERE following_user = "  + str(uid))
			sql_following = cur.fetchall()
        
			cur.execute("SELECT COUNT(user_id) FROM user_followers JOIN users ON (followed_user = user_id) WHERE following_user = "  + str(uid))
			sql_following_count = cur.fetchall()

			return flask.render_template('ProfilePage.html', user=sql_user[0], lists=sql_lists,stats_lists = sql_stats_lists[0], stats_read=sql_stats_read[0], stats_unique=sql_stats_unique[0], stats_pages=sql_stats_pages[0], years = sql_stats_years,friends=sql_following,friendscount=sql_following_count)
	if request.method == 'POST':
		with easypg.cursor() as cur:
			cur.execute("INSERT INTO user_followers (following_user, followed_user) values (%s, %s)",(remember_me, uid,))
			cur.execute("COMMIT")
			username = find_user_name(remember_me)
			return redirect(url_for('home', username=username,remember=remember_me))

#Profile Edit
@app.route('/user/edit/<uid>', methods=['GET', 'POST'])
def profile_edit(uid):
	if request.method == 'GET':
		cur.execute("SELECT * FROM users WHERE user_id = " + str(uid))
		sql_user = cur.fetchall()
		return render_template('ProfileEdit.html', user=sql_user[0])
	if request.method == 'POST':
		name = request.form['name']
                current_username= request.form['current_username']
		current_password= request.form['current_password']
                username = request.form['username']
                password = request.form['password']
                email = request.form['email']
                dob = request.form['dob']
                zipcode = request.form['zipcode']
                contact = request.form['contact']
                bio = request.form['bio']
		cur.execute("SELECT CASE WHEN EXISTS (SELECT *FROM users WHERE (user_name = %s) AND (users.p_word = %s))THEN CAST(1 AS BIT) ELSE CAST(0 AS BIT) END",(current_username,current_password,))
		check = cur.fetchone()
		if check[0] == '1':
			cur.execute("UPDATE users SET (name, email, user_name, DOB, zipcode, bio, trade_contact, p_word) = ($$"+ str(name) +"$$,$$"+ str(email) +"$$,$$"+ str(username) +"$$,$$"+ str(dob) +"$$,$$"+ str(zipcode) +"$$,$$"+ str(bio) +"$$,$$"+ str(contact) +"$$,$$"+ str(password) +"$$) WHERE (user_id=" + str(uid)+ ")")
			cur.execute("COMMIT")
			username = find_user_name(remember_me)
			return redirect(url_for('home', username=username))
		else:
			return redirect(url_for('login'))

#book Details
@app.route('/book/<bid>')
def book_details(bid):
    with easypg.cursor() as cur:
        author_format = ""

        cur.execute("SELECT * FROM books WHERE book_id = " + str(bid))
        sql_book = cur.fetchall()

        cur.execute("SELECT ROUND(AVG(rating)::numeric,2) FROM books JOIN ratings USING(book_id) JOIN users USING (user_id) WHERE book_id = 99--" + str(bid))
        sql_avg_rating = cur.fetchall()

        cur.execute("SELECT author_name FROM book_authors JOIN authors USING(author_id) WHERE book_id = " + str(bid) + " ORDER BY(appear_num) ASC")
        sql_authors = cur.fetchall()

        cur.execute("SELECT user_id,user_name, num_avail,email FROM users JOIN trade_have USING(user_id) JOIN books USING(book_id) WHERE book_id = " + str(bid) + " ORDER BY num_avail LIMIT 10")
        sql_trades = cur.fetchall()

        cur.execute("SELECT user_id, user_name, book_id, title, rating_date, rating FROM books JOIN ratings USING(book_id) JOIN users USING (user_id)  WHERE book_id = " + str(bid) + "  ORDER BY rating_date  DESC LIMIT 10")
        sql_ratings = cur.fetchall()

        cur.execute("SELECT user_id,user_name, post_date, review FROM users JOIN reviews USING(user_id) JOIN books USING(book_id) WHERE book_id = " + str(bid) + " ORDER BY post_date DESC LIMIT 10")
        sql_reviews = cur.fetchall()

    for author_list in sql_authors:
        author_format += author_list[0] + "<br>"

    return flask.render_template('BookDetails.html', book=sql_book,rating_avg= sql_avg_rating,author=author_format, trades=sql_trades, ratings=sql_ratings, reviews=sql_reviews)

#bookAdd
@app.route('/BookAdd' , methods =[ 'GET' , 'POST'])
def book_add():
	if request.method == 'GET':
		return render_template('BookAdd.html')
	if request.method == 'POST':
		title = request.form['title']
		subject = request.form['subject']
		pubdate = request.form['pubdate']
		pagecount = request.form['pagecount']
		isbn = request.form['isbn']
		description = request.form['description']
		pubname = request.form['pubname']
		ed = request.form['ed']
	
		if pubname != None:
			cur.execute("SELECT publisher_id FROM publishers WHERE publisher_name = %s",(pubname,))
			check = cur.fetchall()
			print check
			if check:
				pubid = check[0][0]
				cur.execute("INSERT INTO books(title, subject, publisher_id, publication_date,page_count, ISBN, short_desc, edition) VALUES(%s, %s,%s, %s,%s,%s,%s,%s)",(title,subject,pubid,pubdate, pagecount, isbn, description, ed,))
				cur.execute("COMMIT")
				return redirect(url_for('login'))
			else:
				cur.execute("INSERT INTO publishers(publisher_name) VALUES (%s)",(pubname,))
				cur.execute("COMMIT")
				cur.execute("SELECT publisher_id FROM publishers WHERE publisher_name = %s",(pubname,))
				check = cur.fetchall()
				pubid = check[0][0]
				cur.execute("INSERT INTO books(title,subject,publisher_id,publication_date, page_count,ISBN, short_dec, edition) VALUES(%s,%s,%s,%s,%s,%s,%s,%s)",(title, subject, pubid,pubdate,pagecount,isbn,description,ed,))
				cur.execute("COMMIT")
				return redirect(url_for('login'))
		else:
			flash('Publisher Name must be filled out')
			return redirect(url_for('login'))     
                       
#listView
@app.route('/list/<lid>')
def list_details(lid):
    with easypg.cursor() as cur:
        cur.execute("SELECT user_id FROM list_books JOIN books USING (book_id) JOIN user_lists USING (list_id) JOIN users USING(user_id) WHERE list_id =  "+ str(lid)+" GROUP BY user_id,user_name,name,list_id,list_name")
        sql_list_user_id = cur.fetchall()
        
        cur.execute("SELECT user_name FROM list_books JOIN books USING (book_id) JOIN user_lists USING (list_id) JOIN users USING(user_id) WHERE list_id =  "+ str(lid)+" GROUP BY user_id,user_name,name,list_id,list_name")
        sql_list_user_name = cur.fetchall()
        
        cur.execute("SELECT list_name FROM list_books JOIN books USING (book_id) JOIN user_lists USING (list_id) JOIN users USING(user_id) WHERE list_id =  "+ str(lid)+" GROUP BY user_id,user_name,name,list_id,list_name")
        sql_list_name = cur.fetchall()
        
        cur.execute("SELECT COUNT(book_id)  FROM list_books JOIN books USING (book_id) JOIN user_lists USING (list_id) JOIN users USING(user_id) WHERE list_id =  "+ str(lid)+" GROUP BY user_id,user_name,name,list_id,list_name")
        sql_list_count = cur.fetchall()
        
        cur.execute("SELECT book_id,title,added_date FROM list_books JOIN books USING (book_id) WHERE list_id ="+ str(lid))
        sql_list_books = cur.fetchall()
        
    return render_template('ListView.html', userid=sql_list_user_id[0], nombre=sql_list_user_name[0], list_name=sql_list_name[0], list_count=sql_list_count[0], books=sql_list_books)
    
   
#ListCreate
@app.route('/list/create',methods =[ 'GET', 'POST'])
def list_create():
    if request.method == 'GET':
        return render_template('ListCreate.html')
    if request.method == 'POST':
        list_name = request.form['list_name']
        
        cur.execute("INSERT into user_lists (list_name, user_id) values (%s,%s)",(list_name,remember_me,))
        cur.execute("COMMIT")
        
        cur.execute("SELECT list_id FROM user_lists WHERE (list_name = %s)",(list_name,))
        sql_list_id = cur.fetchall()
        
        return redirect(url_for('list_details',lid=sql_list_id))   
            
            
#ListAdd
@app.route('/list/add/<bid>')
def list_add(bid):
    username=find_user_name(remember_me) 
    userid=find_user_id(username)
    cur.execute("SELECT LIST_ID,LIST_NAME,CREATE_DATE,COUNT(BOOK_ID) FROM user_lists LEFT JOIN list_books USING (list_id) WHERE user_id = "+ str(userid) +" GROUP BY LIST_NAME,CREATE_DATE,LIST_ID ORDER BY CREATE_DATE DESC")
    sql_lists = cur.fetchall()
    
    return render_template('ListConfirm.html',bid=bid,lists=sql_lists)
            
            
#ListInsert
@app.route('/list/insert/<bid>/<list>')
def list_insert(bid,list):
    cur.execute("insert into list_books (list_id, book_id) values (%s, %s)",(list,bid,));
    cur.execute("COMMIT")
    
    return redirect(url_for('list_details',lid=list))                 
            
        
#SearchBooks
@app.route('/search/books/',methods =[ 'GET', 'POST'])
def search_books():
    if request.method == 'GET':
        return render_template('SearchBooks.html')
    if request.method == 'POST':
        search = request.form['search']
        return redirect(url_for('results_books',search=search))
        
#SearchSubject
@app.route('/search/subject')
def search_subject():
    with easypg.cursor() as cur:
        
        cur.execute("SELECT DISTINCT(subject) as subs FROM books ORDER BY subs ASC")
        sql_subjects = cur.fetchall()

    return flask.render_template('SearchSubject.html', subjects=sql_subjects)
    
#ResultsBooks
@app.route('/results/books/<search>')
def results_books(search):  
    with easypg.cursor() as cur:
        print search
        print str(search)
    
        cur.execute("SELECT book_id,title,author_id,author_name,edition,ts_headline(short_desc,plainto_tsquery($$" + str(search) + "$$)) FROM (SELECT book_id, title, author_id, author_name, edition, short_desc, setweight(to_tsvector(title), 'A') || setweight(to_tsvector(subject), 'B') || setweight(to_tsvector(author_name), 'C') || setweight(to_tsvector(coalesce(string_agg(short_desc, ' '))), 'B') as searching FROM books JOIN book_authors USING (book_id) JOIN authors USING (author_id) GROUP BY book_id,author_id, author_name) p_search WHERE p_search.searching @@ plainto_tsquery('english', $$" + str(search) + "$$) ORDER BY ts_rank(p_search.searching, plainto_tsquery('english', $$" + str(search) + "$$)) DESC")
        sql_results_books = cur.fetchall()

        return flask.render_template('ResultsBooks.html', results=sql_results_books,search=search)
        
#SearchUsers
@app.route('/search/users/',methods =[ 'GET', 'POST'])
def search_users():
    if request.method == 'GET':
        return render_template('SearchUsers.html')
    if request.method == 'POST':
        search = request.form['search']
        return redirect(url_for('results_users',search=search))
        
        
#ResultsUsers
@app.route('/results/users/<search>')
def results_users(search):  
    with easypg.cursor() as cur:
        print search
        print str(search)
        cur.execute("SELECT user_id,name,user_name,email,ts_headline(coalesce(bio,' '),plainto_tsquery($$" + str(search) + "$$)) FROM (SELECT user_id, name,user_name, email, bio, setweight(to_tsvector(user_name), 'A') || setweight(to_tsvector(name), 'B') || setweight(to_tsvector( email), 'C') || setweight(to_tsvector(bio), 'D')  as searching FROM users GROUP BY user_id) u_search WHERE u_search.searching @@ plainto_tsquery('english', $$" + str(search) + "$$) ORDER BY ts_rank(u_search.searching, plainto_tsquery('english', $$" + str(search) + "$$)) DESC")
        sql_results_users = cur.fetchall()

        return flask.render_template('ResultsUsers.html', results=sql_results_users,search=search)

#AddtoReadList
@app.route('/read/<bid>', methods = ['GET','POST'])
def readList(bid):
	if request.method == 'GET':
		return render_template('ConfirmAdd.html')
	if request.method == 'POST':
		numread=request.form['numread']
		begindate=request.form['begindate']
		finishdate = request.form['finishdate']
		cur.execute("INSERT INTO read_list(book_id, user_id, num_read, begin_date, finish_date) VALUES(%s,%s,%s,%s,%s)",(bid,remember_me, numread, begindate,finishdate,))
		cur.execute("COMMIT")
		username=find_user_name(remember_me) 
		return redirect(url_for('home',username=username)) 


if __name__ == '__main__':
	app.run(host ='0.0.0.0',debug = True)
