# Makefile

# === Variables ===
# Input/Output files
MARKDOWN_FILE = record.md
PDF_FILE = record.pdf

# Configuration and Tools
TEMPLATE_FILE = template.tex
FILES ?= ../.
GENERATION_SCRIPT = ./generate-markdown.sh
PANDOC_METADATA = metadata.yaml
PANDOC_HEADER_INCLUDE = deeplists.tex
PDF_VIEWER = zathura

# === Targets ===
all: $(PDF_FILE)

$(MARKDOWN_FILE): $(GENERATION_SCRIPT)
	@echo "--- Generating Markdown file: $(MARKDOWN_FILE) using files from $(FILES) ---"
	$(GENERATION_SCRIPT) $(MARKDOWN_FILE) $(FILES)

$(PDF_FILE): $(MARKDOWN_FILE) $(TEMPLATE_FILE) $(PANDOC_METADATA) $(PANDOC_HEADER_INCLUDE)
	@echo "--- Generating PDF file: $(PDF_FILE) ---"
	pandoc \
	--output=$(PDF_FILE) \
	--standalone \
	--include-in-header=$(PANDOC_HEADER_INCLUDE) \
	--metadata-file=$(PANDOC_METADATA) \
	--template=$(TEMPLATE_FILE) \
	--from=markdown \
	--to=pdf \
	$(MARKDOWN_FILE) || { \
		echo "ERROR: Failed to generate PDF file."; \
		echo "Run make checkdepends to ensure all dependencies are met."; \
		exit 1; \
	}

# Explicitly run the Markdown generation step.
markdown: $(MARKDOWN_FILE)
	@echo "--- Markdown file ensured up-to-date ---"

# Explicitly run the PDF generation step.
pdf: $(PDF_FILE)
	@echo "--- PDF file ensured up-to-date ---"

# Show the generated PDF file
show: $(PDF_FILE)
	@echo "--- Showing PDF file: $(PDF_FILE) ---"
	$(PDF_VIEWER) $(PDF_FILE) &

# Clean up generated files
clean:
	@echo "--- Cleaning generated files ---"
	rm -f $(MARKDOWN_FILE)

# Check dependencies
checkdepends:
	@echo "--- Checking dependencies ---"
	./check-dependencies-pandoc.sh

# Declare targets that do not correspond to actual files.
# This prevents issues if a file with the same name exists and
# ensures the commands always run when the target is invoked (unless prerequisites stop it).
.PHONY: all pdf markdown show clean
