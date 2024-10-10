from pathlib import Path

from jinja2 import Environment, FileSystemLoader
from markdown import Markdown
from markdown.extensions.toc import slugify_unicode

env = Environment(loader=FileSystemLoader('docs'))

TOC_CONFIG = {
    'slugify': slugify_unicode,
    'toc_depth': 2
}


def toc_stringify(toc: dict[str, str] | list) -> list[str]:
    """Convert TOC tokens to a list of strings."""
    if isinstance(toc, list):
        result = []
        for t in toc:
            result.extend(toc_stringify(t))
        return result

    if toc['data-toc-label']:
        name = toc['data-toc-label']
    else:
        name = toc['name']
    name = name.replace('[', '\\[').replace(']', '\\]')
    l = toc['level']
    result = [' ' * 4 * (l - 1) + f'-   [{name}](#{toc["id"]})']
    result.extend(toc_stringify(toc['children']))
    return result


def build(filename: str) -> tuple[str, str]:
    """
    Render a file and generate TOC,
    and then save to file.
    Return (filename, content)
    """

    template = env.get_template(filename)
    content = template.render()

    md = Markdown(extensions=['meta', 'toc'],
                  extension_configs={'toc': TOC_CONFIG})
    md.convert(content)

    lines = md.lines
    try:
        toc_idx = lines.index('[TOC]')
        toc = md.toc_tokens
        toc = toc_stringify(toc)
        lines = lines[:toc_idx] + toc + lines[toc_idx + 1:]
    except ValueError:
        pass

    content = '\n'.join(lines).strip() + '\n'

    meta = md.Meta
    output = meta.get('output', [None])[0]

    if output is None:
        raise RuntimeError("I don't know where to save the output file.")

    with open(output, 'w', encoding='utf-8') as f:
        f.write(content)

    return output, content


if __name__ == '__main__':
    for file in Path('docs').iterdir():
        if not (file.is_file() and file.suffix == '.md'):
            continue
        print(f'Building `{file.name}`...')
        build(file.name)
        print('Done.')
