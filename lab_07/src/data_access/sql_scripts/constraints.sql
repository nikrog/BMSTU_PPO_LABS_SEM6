ALTER TABLE BA.clients
    ADD CONSTRAINT checkPassport check (passport_num > 0);

ALTER TABLE BA.clients
    ADD CONSTRAINT checkBirthDate check (birth_date <= '2010-12-31'::date);

ALTER TABLE BA.clients
    ADD CONSTRAINT checkPhone check (phone LIKE '+%');

ALTER TABLE BA.products
    ADD CONSTRAINT checkPtype check (ptype >= 0 AND ptype < 2);

ALTER TABLE BA.products
    ADD CONSTRAINT checkMinTime check (min_time > 0);

ALTER TABLE BA.products
    ADD CONSTRAINT checkMaxTime check (max_time > 0 AND max_time >= min_time);

ALTER TABLE BA.products
    ADD CONSTRAINT checkMinSum check (min_sum > 0);

ALTER TABLE BA.products
    ADD CONSTRAINT checkMaxSum check (max_sum > 0 AND max_sum >= min_sum);

ALTER TABLE BA.products
    ADD CONSTRAINT checkCurrency check (currency >= 0 AND currency < 4);

ALTER TABLE BA.products
    ADD CONSTRAINT checkSumRating check (sum_rating >= 0);

ALTER TABLE BA.products
    ADD CONSTRAINT checkCountRating check (count_rating >= 0);

ALTER TABLE BA.requests
    ADD CONSTRAINT checkSum check (sum > 0);

ALTER TABLE BA.requests
    ADD CONSTRAINT checkDuration check (duration > 0);

ALTER TABLE BA.requests
    ADD CONSTRAINT checkDate check (date >= 0);

ALTER TABLE BA.requests
    ADD CONSTRAINT checkState check (state >= 0 AND state < 6);

ALTER TABLE BA.banks
    ADD CONSTRAINT checkLicenseNum check (license_num > 0);

ALTER TABLE BA.banks
    ADD CONSTRAINT checkPhone check (phone LIKE '+%');