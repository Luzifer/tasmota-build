#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import os
import sys

import yaml


def fmt_line(prefix, param, content, comment):
    return '{: <47}  // {}'.format('{}#define {: <22} {}'.format(prefix, param, content), comment)


def get_line(param, content, comment):
    if content == '!undef':
        return fmt_line('//', param, '', comment)
    if content == '!def':
        return fmt_line('', param, '', comment)

    if content[:2] == '${':
        envvar = content.strip('${}')
        if envvar in os.environ:
            content = os.environ[envvar]

    return fmt_line('', param, content, comment)


def main():
    cfg = yaml.load(open(sys.argv[1]))
    config = open('tasmota/sonoff/user_config.h').read().split('\n')

    for (i, line) in enumerate(config):
        for param, content in cfg.items():
            if '#define {} '.format(param) in line:
                comment = line.lstrip('/').split(' //', 1)[1].strip()
                config[i] = get_line(param, content, comment)

    with open('tasmota/sonoff/user_config.h', 'w') as fh:
        fh.write('\n'.join(config))


if __name__ == '__main__':
    main()
