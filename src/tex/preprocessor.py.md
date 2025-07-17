---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n# encoding: utf-8\n\n# Source code preprocessor for\
    \ KACTL build process.\n# License: CC0\n\nimport sys\nimport getopt\nimport subprocess\n\
    \n\ndef escape(input):\n    input = input.replace('<', r'\\ensuremath{<}')\n \
    \   input = input.replace('>', r'\\ensuremath{>}')\n    return input\n\ndef pathescape(input):\n\
    \    input = input.replace('\\\\', r'\\\\')\n    input = input.replace('_', r'\\\
    _')\n    input = escape(input)\n    return input\n\ndef codeescape(input):\n \
    \   input = input.replace('_', r'\\_')\n    input = input.replace('\\n', '\\\\\
    \\\\\\n')\n    input = input.replace('{', r'\\{')\n    input = input.replace('}',\
    \ r'\\}')\n    input = input.replace('^', r'\\ensuremath{\\hat{\\;}}')\n    input\
    \ = escape(input)\n    return input\n\ndef ordoescape(input, esc=True):\n    if\
    \ esc:\n        input = escape(input)\n    start = input.find(\"O(\")\n    if\
    \ start >= 0:\n        bracketcount = 1\n        end = start+1\n        while\
    \ end+1<len(input) and bracketcount>0:\n            end = end + 1\n          \
    \  if input[end] == '(':\n                bracketcount = bracketcount + 1\n  \
    \          elif input[end] == ')':\n                bracketcount = bracketcount\
    \ - 1\n        if bracketcount == 0:\n            return r\"%s\\bigo{%s}%s\" %\
    \ (input[:start], input[start+2:end], ordoescape(input[end+1:], False))\n    return\
    \ input\n\ndef addref(caption, outstream):\n    caption = pathescape(caption).strip()\n\
    \    print(r\"\\kactlref{%s}\" % caption, file=outstream)\n    with open('header.tmp',\
    \ 'a') as f:\n        f.write(caption + \"\\n\")\n\nCOMMENT_TYPES = [\n    ('/**',\
    \ '*/'),\n    (\"'''\", \"'''\"),\n    ('\"\"\"', '\"\"\"'),\n]\n\ndef find_start_comment(source,\
    \ start=None):\n    first = (-1, -1, None)\n    for s, e in COMMENT_TYPES:\n \
    \       i = source.find(s, start)\n        if i != -1 and (i < first[0] or first[0]\
    \ == -1):\n            first = (i, i + len(s), e)\n\n    return first\n\ndef processwithcomments(caption,\
    \ instream, outstream, listingslang):\n    knowncommands = ['Author', 'Date',\
    \ 'Description', 'Source', 'Time', 'Memory', 'License', 'Status', 'Usage', 'Details']\n\
    \    requiredcommands = []\n    includelist = []\n    error = \"\"\n    warning\
    \ = \"\"\n    # Read lines from source file\n    try:\n        lines = instream.readlines()\n\
    \    except:\n        error = \"Could not read source.\"\n        lines = []\n\
    \    nlines = list()\n    for line in lines:\n        if 'exclude-line' in line:\n\
    \            continue\n        if 'include-line' in line:\n            line =\
    \ line.replace('// ', '', 1)\n        had_comment = \"///\" in line\n        keep_include\
    \ = 'keep-include' in line\n        # Remove /// comments\n        line = line.split(\"\
    ///\")[0].rstrip()\n        # Remove '#pragma once' lines\n        if line ==\
    \ \"#pragma once\":\n            continue\n        if had_comment and not line:\n\
    \            continue\n        # Check includes\n        include = parse_include(line)\n\
    \        if include is not None and not keep_include:\n            includelist.append(include)\n\
    \            continue\n        nlines.append(line)\n    # Remove and process multiline\
    \ comments\n    source = '\\n'.join(nlines)\n    nsource = ''\n    start, start2,\
    \ end_str = find_start_comment(source)\n    end = 0\n    commands = {}\n    while\
    \ start >= 0 and not error:\n        nsource = nsource.rstrip() + source[end:start]\n\
    \        end = source.find(end_str, start2)\n        if end<start:\n         \
    \   error = \"Invalid %s %s comments.\" % (source[start:start2], end_str)\n  \
    \          break\n        comment = source[start2:end].strip()\n        end +=\
    \ len(end_str)\n        start, start2, end_str = find_start_comment(source, end)\n\
    \n        commentlines = comment.split('\\n')\n        command = None\n      \
    \  value = \"\"\n        for cline in commentlines:\n            allow_command\
    \ = False\n            cline = cline.strip()\n            if cline.startswith('*'):\n\
    \                cline = cline[1:].strip()\n                allow_command = True\n\
    \            ind = cline.find(':')\n            if allow_command and ind != -1\
    \ and ' ' not in cline[:ind] and cline[0].isalpha() and cline[0].isupper():\n\
    \                if command:\n                    if command not in knowncommands:\n\
    \                        error = error + \"Unknown command: \" + command + \"\
    . \"\n                    commands[command] = value.lstrip()\n               \
    \ command = cline[:ind]\n                value = cline[ind+1:].strip()\n     \
    \       else:\n                value = value + '\\n' + cline\n        if command:\n\
    \            if command not in knowncommands:\n                error = error +\
    \ \"Unknown command: \" + command + \". \"\n            commands[command] = value.lstrip()\n\
    \    for rcommand in sorted(set(requiredcommands) - set(commands)):\n        error\
    \ = error + \"Missing command: \" + rcommand + \". \"\n    if end>=0:\n      \
    \  nsource = nsource.rstrip() + source[end:]\n    nsource = nsource.strip()\n\n\
    \    if listingslang in ['C++', 'Java']:\n        hash_script = 'hash'\n     \
    \   p = subprocess.Popen(['sh', 'src/contest/%s.sh' % hash_script], stdin=subprocess.PIPE,\
    \ stdout=subprocess.PIPE, encoding=\"utf-8\")\n        hsh, _ = p.communicate(nsource)\n\
    \        hsh = hsh.split(None, 1)[0]\n        hsh = hsh + ', '\n    else:\n  \
    \      hsh = ''\n    # Produce output\n    out = []\n    if warning:\n       \
    \ out.append(r\"\\kactlwarning{%s: %s}\" % (caption, warning))\n    if error:\n\
    \        out.append(r\"\\kactlerror{%s: %s}\" % (caption, error))\n    else:\n\
    \        addref(caption, outstream)\n        if commands.get(\"Description\"):\n\
    \            out.append(r\"\\defdescription{%s}\" % escape(commands[\"Description\"\
    ]))\n        if commands.get(\"Usage\"):\n            out.append(r\"\\defusage{%s}\"\
    \ % codeescape(commands[\"Usage\"]))\n        if commands.get(\"Time\"):\n   \
    \         out.append(r\"\\deftime{%s}\" % ordoescape(commands[\"Time\"]))\n  \
    \      if commands.get(\"Memory\"):\n            out.append(r\"\\defmemory{%s}\"\
    \ % ordoescape(commands[\"Memory\"]))\n        if includelist:\n            out.append(r\"\
    \\leftcaption{%s}\" % pathescape(\", \".join(includelist)))\n        if nsource:\n\
    \            out.append(r\"\\rightcaption{%s%d lines}\" % (hsh, len(nsource.split(\"\
    \\n\"))))\n        langstr = \", language=\"+listingslang\n        out.append(r\"\
    \\begin{lstlisting}[caption={%s}%s]\" % (pathescape(caption), langstr))\n    \
    \    out.append(nsource)\n        out.append(r\"\\end{lstlisting}\")\n\n    for\
    \ line in out:\n        print(line, file=outstream)\n\ndef processraw(caption,\
    \ instream, outstream, listingslang = 'raw'):\n    try:\n        source = instream.read().strip()\n\
    \        addref(caption, outstream)\n        print(r\"\\rightcaption{%d lines}\"\
    \ % len(source.split(\"\\n\")), file=outstream)\n        print(r\"\\begin{lstlisting}[language=%s,caption={%s}]\"\
    \ % (listingslang, pathescape(caption)), file=outstream)\n        print(source,\
    \ file=outstream)\n        print(r\"\\end{lstlisting}\", file=outstream)\n   \
    \ except:\n        print(r\"\\kactlerror{Could not read source.}\", file=outstream)\n\
    \ndef parse_include(line):\n    line = line.strip()\n    if line.startswith(\"\
    #include\"):\n        return line[8:].strip()\n    return None\n\ndef getlang(input):\n\
    \    return input.rsplit('.',1)[-1]\n\ndef getfilename(input):\n    return input.rsplit('/',1)[-1]\n\
    \ndef print_header(data, outstream):\n    parts = data.split('|')\n    until =\
    \ parts[0].strip() or parts[1].strip()\n    if not until:\n        # Nothing on\
    \ this page, skip it.\n        return\n    with open('header.tmp') as f:\n   \
    \     lines = [x.strip() for x in f.readlines()]\n    if until not in lines:\n\
    \        # Nothing new on the page.\n        return\n\n    ind = lines.index(until)\
    \ + 1\n    header_length = len(\"\".join(lines[:ind]))\n    def adjust(name):\n\
    \        return name if name.startswith('.') else name.split('.')[0]\n    output\
    \ = r\"\\enspace{}\".join(map(adjust, lines[:ind]))\n    font_size = 10\n    if\
    \ header_length > 150:\n        font_size = 8\n    output = r\"\\hspace{3mm}\\\
    textbf{\" + output + \"}\"\n    output = \"\\\\fontsize{%d}{%d}\" % (font_size,\
    \ font_size) + output\n    print(output, file=outstream)\n    with open('header.tmp',\
    \ 'w') as f:\n        for line in lines[ind:]:\n            f.write(line + \"\\\
    n\")\n\ndef main():\n    language = None\n    caption = None\n    instream = sys.stdin\n\
    \    outstream = sys.stdout\n    print_header_value = None\n    try:\n       \
    \ opts, args = getopt.getopt(sys.argv[1:], \"ho:i:l:c:\", [\"help\", \"output=\"\
    , \"input=\", \"language=\", \"caption=\", \"print-header=\"])\n        for option,\
    \ value in opts:\n            if option in (\"-h\", \"--help\"):\n           \
    \     print(\"This is the help section for this program\")\n                print()\n\
    \                print(\"Available commands are:\")\n                print(\"\\\
    t -o --output\")\n                print(\"\\t -h --help\")\n                print(\"\
    \\t -i --input\")\n                print(\"\\t -l --language\")\n            \
    \    print(\"\\t --print-header\")\n                return\n            if option\
    \ in (\"-o\", \"--output\"):\n                outstream = open(value, \"w\")\n\
    \            if option in (\"-i\", \"--input\"):\n                instream = open(value)\n\
    \                if language == None:\n                    language = getlang(value)\n\
    \                if caption == None:\n                    caption = getfilename(value)\n\
    \            if option in (\"-l\", \"--language\"):\n                language\
    \ = value\n            if option in (\"-c\", \"--caption\"):\n               \
    \ caption = value\n            if option == \"--print-header\":\n            \
    \    print_header_value = value\n        if print_header_value is not None:\n\
    \            print_header(print_header_value, outstream)\n            return\n\
    \        print(\" * \\x1b[1m{}\\x1b[0m\".format(caption))\n        if language\
    \ in [\"cpp\", \"cc\", \"c\", \"h\", \"hpp\"]:\n            processwithcomments(caption,\
    \ instream, outstream, 'C++')\n        elif language in [\"java\", \"kt\"]:\n\
    \            processwithcomments(caption, instream, outstream, 'Java')\n     \
    \   elif language == \"ps\":\n            processraw(caption, instream, outstream)\
    \ # PostScript was added in listings v1.4\n        elif language == \"raw\":\n\
    \            processraw(caption, instream, outstream)\n        elif language ==\
    \ \"rawcpp\":\n            processraw(caption, instream, outstream, 'C++')\n \
    \       elif language == \"sh\":\n            processraw(caption, instream, outstream,\
    \ 'bash')\n        elif language == \"py\":\n            processwithcomments(caption,\
    \ instream, outstream, 'Python')\n        elif language == \"rawpy\":\n      \
    \      processraw(caption, instream, outstream, 'Python')\n        else:\n   \
    \         raise ValueError(\"Unknown language: \" + str(language))\n    except\
    \ (ValueError, getopt.GetoptError, IOError) as err:\n        print(str(err), file=sys.stderr)\n\
    \        print(\"\\t for help use --help\", file=sys.stderr)\n        return 2\n\
    \nif __name__ == \"__main__\":\n    exit(main())\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tex/preprocessor.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tex/preprocessor.py
layout: document
redirect_from:
- /library/src/tex/preprocessor.py
- /library/src/tex/preprocessor.py.html
title: src/tex/preprocessor.py
---
