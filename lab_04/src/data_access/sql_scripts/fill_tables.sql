INSERT INTO BA.users (login, password, permission) VALUES
('admin', 'admin', 3);

INSERT INTO BA.banks (name, license_num, address, email, phone, website) VALUES
('test', 1234, 'testovaya ulitsa', 'test@bank.ru', '+74953459870', 'testbank.ru');

INSERT INTO BA.products (ptype, name, bank_id, rate, min_time, max_time,
                         min_sum, max_sum, currency, sum_rating, count_rating)  VALUES
(0, 'test', 1, 7.5, 10, 750, 10000, 1000000, 0, 0, 0);

INSERT INTO BA.products (ptype, name, bank_id, rate, min_time, max_time,
                         min_sum, max_sum, currency, sum_rating, count_rating)  VALUES
(1, 'test_credit', 1, 12.5, 1, 750, 100000, 3000000, 0, 21, 5);
