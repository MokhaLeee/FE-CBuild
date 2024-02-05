all:
	@$(MAKE) -C Kernel $@

pre_build:
	@$(MAKE) -C Kernel $@

clean:
	@$(MAKE) -C Kernel $@ > /dev/null

clean_basic:
	@$(MAKE) -C Kernel $@ > /dev/null
