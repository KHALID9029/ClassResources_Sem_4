create table BANK
(
    bank_id int,
    bank_name varchar(50),
    bank_address varchar(100),
    bank_email varchar(50),
    bank_phone varchar(20),
    PRIMARY KEY (bank_id)
);


create TABLE BRANCH
(
    branch_id int,
    branch_name varchar(50),
    branch_address varchar(100),
    branch_email varchar(50),
    branch_phone varchar(20),
    bank_id int,
    PRIMARY KEY (branch_id),
    FOREIGN KEY (bank_id) REFERENCES bank(bank_id)
);

create TABLE ACCOUNT
(
    account_id int,
    account_type varchar(50),
    account_balance numeric(12,2),
    branch_id int,
    PRIMARY KEY (account_id),
    FOREIGN KEY (branch_id) REFERENCES branch(branch_id)
);

create TABLE CUSTOMER
(
    customer_id int,
    customer_name varchar(50),
    customer_address varchar(100),
    customer_email varchar(50),
    customer_phone varchar(20),
    account_id int,
    PRIMARY KEY (customer_id),
    FOREIGN KEY (account_id) REFERENCES account(account_id)
);

create TABLE TRANSACTION
(
    transaction_id int,
    transaction_type varchar(50),
    transaction_amount numeric(12,2),
    transaction_date date,
    account_id int,
    PRIMARY KEY (transaction_id),
    FOREIGN KEY (account_id) REFERENCES account(account_id)
);

CREATE TABLE LOAN
(
    loan_id int,
    loan_type varchar(50),
    loan_amount numeric(12,2),
    loan_date date,
    account_id int,
    branch_id int,
    PRIMARY KEY (loan_id),
    FOREIGN KEY (account_id) REFERENCES account(account_id),
    FOREIGN KEY (branch_id) REFERENCES branch(branch_id)
);