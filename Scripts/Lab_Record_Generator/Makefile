# Makefile

# === Variables ===
# Input/Output files
MARKDOWN_FILE = record.md
PDF_FILE = record.pdf
DOCX_FILE = record.docx
ODT_FILE = record.odt
INTERMEDIATE_FORMAT ?= MARKDOWN

# Code filenames
include config.mk

# Configuration and Tools
TEMPLATE_FILE = template.tex
FILES ?= ../.
GENERATION_SCRIPT = ./generate-markdown.sh
DEPENDENCIES_SCRIPT = ./check-dependencies.sh
PANDOC_METADATA = metadata.yaml
PANDOC_HEADER_INCLUDE = header.tex
PDF_VIEWER = zathura
LIBREOFFICE_TOOL = libreoffice

# === Targets ===
all: $(PDF_FILE)

# Main PDF generation rule that selects the appropriate method
$(PDF_FILE): $($(INTERMEDIATE_FORMAT:=_FILE))
	@echo "--- Generating PDF file: $(PDF_FILE) ---"
	@if [ "$(INTERMEDIATE_FORMAT)" = "MARKDOWN" ]; then \
		echo "Using pandoc for conversion from $(INTERMEDIATE_FORMAT)"; \
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
		}; \
	else \
		echo "Using $(LIBREOFFICE_TOOL) for conversion from $(INTERMEDIATE_FORMAT)"; \
		$(LIBREOFFICE_TOOL) --convert-to pdf $($(INTERMEDIATE_FORMAT:=_FILE)) || { \
			echo "ERROR: Failed to generate PDF file."; \
			echo "Run make checkdepends to ensure all dependencies are met."; \
			exit 1; \
		}; \
	fi
	@echo "--- Generated PDF file: $(PDF_FILE) ---"

$(DOCX_FILE): $(MARKDOWN_FILE)
	@echo "--- Generating DOCX file: $(DOCX_FILE) ---"
	pandoc \
		--output=$(DOCX_FILE) \
		--metadata-file=$(PANDOC_METADATA) \
		--standalone \
		--from=markdown \
		--to=docx \
		$(MARKDOWN_FILE)

$(ODT_FILE): $(MARKDOWN_FILE)
	@echo "--- Generating ODT file: $(ODT_FILE) ---"
	pandoc \
		--output=$(ODT_FILE) \
		--metadata-file=$(PANDOC_METADATA) \
		--standalone \
		--from=markdown \
		--to=odt \
		$(MARKDOWN_FILE)

$(MARKDOWN_FILE): $(GENERATION_SCRIPT)
	@echo "--- Generating Markdown file $(MARKDOWN_FILE) using files from $(FILES) ---"
	MAIN_CODE_FILENAME="$(MAIN_CODE_FILENAME)" CODE_EXTENSIONS="$(CODE_EXTENSIONS)" EXCLUDED_FOLDERS="$(EXCLUDED_FOLDERS)" $(GENERATION_SCRIPT) $(MARKDOWN_FILE) $(FILES)

# Explicitly run the PDF generation step.
pdf: $(PDF_FILE)
	@echo "--- PDF file ensured up-to-date ---"

# Explicitly run the Markdown generation step.
markdown: $(MARKDOWN_FILE)
	@echo "--- Markdown file ensured up-to-date ---"

# Explicitly run the docx generation step.
docx: $(DOCX_FILE)
	@echo "--- DOCX file ensured up-to-date ---"

odt: $(ODT_FILE)
	@echo "--- ODT file ensured up-to-date ---"

# Show the generated PDF file
show: $(PDF_FILE)
	@echo "--- Showing PDF file: $(PDF_FILE) ---"
	$(PDF_VIEWER) $(PDF_FILE) &

# Clean up generated files
clean:
	@echo "--- Cleaning generated files ---"
	rm -f $(DOCX_FILE) $(ODT_FILE) $(PDF_FILE) $(MARKDOWN_FILE)

# Check dependencies
checkdepends:
	@echo "--- Checking dependencies ---"
	$(DEPENDENCIES_SCRIPT)

# Declare targets that do not correspond to actual files.
.PHONY: all pdf markdown docx odt show clean checkdepends
