# Makefile

# Variables
INPUT = record.md
OUTPUT = record.pdf
TEMPLATE = template.tex

# Create PDF
all: $(OUTPUT)
$(OUTPUT): $(INPUT) $(TEMPLATE)
	pandoc \
	--output=$(OUTPUT) \
	--standalone \
	--template=$(TEMPLATE) \
	--from=markdown \
	--to=pdf \
	$(INPUT)

# Show PDF
show: all $(OUTPUT)
	zathura $(OUTPUT)

clean:
	rm -f $(OUTPUT)


