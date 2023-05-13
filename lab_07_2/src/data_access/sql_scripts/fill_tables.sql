INSERT INTO BA.users (login, password, permission) VALUES
('admin', 'admin', 3);

INSERT INTO BA.users (login, password, permission) VALUES
('manager', '1111', 2);

INSERT INTO BA.users (login, password, permission) VALUES
('client', '2222', 1);

INSERT INTO BA.users (login, password, permission) VALUES
('client2', '2223', 1);

INSERT INTO BA.banks (name, license_num, address, email, phone, website) VALUES
('Альфа банк', 1234, 'Москва', 'alphabank@alpha.ru', '+74953459872', 'alphabank.ru')
RETURNING bank_id;

INSERT INTO BA.banks (name, license_num, address, email, phone, website) VALUES
('Райфайзен банк', 1235, 'Москва', 'raifaizen@raif.ru', '+74953459873', 'raiffaizen.ru');

INSERT INTO BA.clients (name, surname, patronymic, passport_num, birth_date, address, email, phone, user_id) VALUES
('b', 'b', 'b', 77779, 1986, 'Street 9', 'b@mail.ru', '+79183456781', 4);

INSERT INTO BA.products (ptype, name, bank_id, rate, min_time, max_time,
                         min_sum, max_sum, currency, sum_rating, count_rating)  VALUES
(0, 'test', 1, 7.5, 10, 750, 10000, 1000000, 0, 0, 0);

INSERT INTO BA.products (ptype, name, bank_id, rate, min_time, max_time,
                         min_sum, max_sum, currency, sum_rating, count_rating)  VALUES
(1, 'test_credit', 1, 12.5, 1, 750, 100000, 3000000, 0, 21, 5);

copy BA.products (ptype, name, bank_id, rate, min_time, max_time,
                         min_sum, max_sum, currency, sum_rating, count_rating)
    from '/db_data/products.csv' delimiter ',';

SELECT date FROM BA.requests
WHERE date > '2023-05-06 15:20:55.000000';

SELECT * FROM BA.banks
ORDER BY bank_id DESC;
