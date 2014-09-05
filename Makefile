MODULE=.libs/mod_forbidden_not_found.so

all: $(MODULE)

.libs/%.so: %.c
	apxs -c $<
